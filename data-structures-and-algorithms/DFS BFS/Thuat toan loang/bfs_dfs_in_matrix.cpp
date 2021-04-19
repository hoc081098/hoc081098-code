//
// Created by Peter Hoc on 23/03/2018.
//

#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <forward_list>

struct point {
    int x, y;

    friend bool operator==(const point &lhs, const point &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    friend bool operator!=(const point &lhs, const point &rhs) {
        return !(rhs == lhs);
    }


    friend std::ostream &operator<<(std::ostream &os, const point &point) {
        return os << '(' << point.x << ", " << point.y << ')';
    }
};

namespace std {
    template<>
    struct hash<point> {
        std::size_t operator()(const point &point) const {
            size_t res = 17;
            res = res * 31 + hash<int>()(point.x);
            res = res * 31 + hash<int>()(point.y);
            return res;
        }
    };

}

struct point_queue : public std::queue<point> {
    const value_type &top() {
        return queue::front();
    }
};

template<typename _Sequence>
std::forward_list<point> find_path(const std::vector<std::vector<int>> &matrix, const point &begin, const point &end);

template<typename _Sequence>
std::ostream &operator<<(std::ostream &os, const std::forward_list<_Sequence> &list);

int main() {
    /**
     *     O------->x
     *     |
     *     |
     *     |
     *     y
     */
    std::vector<std::vector<int>> matrix{
            {1, 1, 0, 1, 0, 1},
            {1, 1, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 1},
            {1, 0, 0, 1, 1, 0},
            {1, 0, 0, 1, 1, 1},
            {1, 0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 1, 1},
    };
    const point begin = {0, 0};
    const point end = {int(matrix[0].size() - 1), int(matrix.size() - 1)};

    std::cout << "path1 by DFS: " << find_path<std::stack<point>>(matrix, begin, end) << '\n';
    std::cout << "path2 by BFS: " << find_path<point_queue>(matrix, begin, end) << '\n';
}

template<typename _Sequence>
std::forward_list<point> find_path(const std::vector<std::vector<int>> &matrix, const point &begin, const point &end) {
    _Sequence sequence;
    sequence.push(begin);

    std::unordered_map<point, bool> visited{
            {begin, true}
    };
    std::unordered_map<point, point> pre;


    while (!sequence.empty()) {
        point const current = sequence.top();

        if (current == end) {
            std::forward_list<point> path;

            point p = end;
            while (p != begin) {
                path.push_front(p);
                p = pre[p];
            }
            path.push_front(begin);

            return path;
        }

        sequence.pop();

        static std::vector<point> direction{
                {1,  0},
                {0,  1},
                {-1, 0},
                {0,  -1}
        };
        for (const point &d : direction) {
            const int x = current.x + d.x;
            const int y = current.y + d.y;

            if (x < 0 || x >= matrix[0].size() || y < 0 || y >= matrix.size() || !matrix[y][x]) continue;

            const point adj = {x, y};
            if (!visited[adj]) {
                pre[adj] = current;
                sequence.push(adj);
                visited[adj] = true;
            }
        }
    }

    return {};
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::forward_list<T> &list) {
    os << '[';
    auto cend = list.cend();
    for (auto it = list.cbegin(); it != cend; ++it) {
        os << *it
           << (std::next(it) != cend ? ", " : "");
    }
    return os << ']';
}