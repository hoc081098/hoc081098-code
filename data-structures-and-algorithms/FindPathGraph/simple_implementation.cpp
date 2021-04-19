//
// Created by Peter Hoc on 31/03/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <limits>
#include <iomanip>

using namespace std;

vector<unordered_map<size_t, float>> adj_list;
unordered_map<string, string> road_name;
size_t E, V, start, goal;

void readFile(const char *fileName);

template<typename _Container>
void find_path();

void ucs();

void update(vector<size_t> &heap, vector<float> &d, unordered_map<size_t, size_t> &index, size_t v);

void pop(vector<size_t> &heap, vector<float> &d, unordered_map<size_t, size_t> &index);

void printPath(const vector<size_t> &pre);

void getDataFromLine(const string &line);

template<class T>
class my_queue : public queue<T> {
public:
    const T &top() {
        return queue<T>::front();
    }
};

int main() {
    //readFile("input");

    ////
    string s = "0 1 Nguyen_Tri_Phuong 1\n"
            "0 2 Ly_Thai_To 0.8\n"
            "0 3 Thanh_Thai 1\n"
            "0 4 3_Thang_2 1.6\n"
            "0 5 3_Thang_2 1.2\n"
            "1 2 Ngo_Gia_Tu 1\n"
            "1 7 Nguyen_Chi_Thanh 1\n"
            "1 8 Nguyen_Chi_Thanh 0.6\n"
            "2 9 Ly_Thai_To 0.5\n"
            "3 6 Lu_Gia 0.9\n"
            "3 12 Lu_gia 0.5\n"
            "4 12 CMT8 1\n"
            "4 13 CMT8 1.2\n"
            "5 6 Ly_Thuong_Kiet 0.6\n"
            "5 7 Ly_Thuong_Kiet 0.4\n"
            "7 11 Ly_Thuong_Kiet 0.8\n"
            "8 9 Hung_Vuong 0.6\n"
            "9 10 Nguyen_Van_Cu 0.8\n"
            "9 13 Nguyen_Thi_Minh_Khai 1.3\n"
            "10 11 An_Duong_Vuong 2.3\n"
            "10 14 Nguyen_Van_Cu 0.3\n"
            "13 15 CMT8 1.4\n"
            "14 15 Tran_Hung_Dao 1.8";

    start = 12;
    goal = 14;
    V = 16;
    E = 23;
    adj_list.resize(V);
    string line;
    for (istringstream iss(s); std::getline(iss, line); getDataFromLine(line)) {}
    ////

    cout << "DFS: ";
    find_path<stack<size_t >>();

    cout << "BFS: ";
    find_path<my_queue<size_t>>();

    cout << "UCS: ";
    ucs();
}

void ucs() {
    vector<float> d(V, numeric_limits<float>::max());
    d[start] = 0;
    vector<size_t> heap{0};
    unordered_map<size_t, size_t> index;
    update(heap, d, index, start);

    vector<bool> visited(V, false);
    vector<size_t> pre(V, 0);

    while (heap.size() > 1) {
        auto current = heap[1];


        if (current == goal) {
            printPath(pre);
            return;
        }

        pop(heap, d, index);
        visited[current] = true;

        for (const auto &adj_vertex : adj_list[current]) {
            auto v = adj_vertex.first;
            if (visited[v]) continue;

            auto w = adj_vertex.second;

            auto new_distance = d[current] + w;
            if (new_distance < d[v]) {
                d[v] = new_distance;
                update(heap, d, index, v);
                pre[v] = current;
            }
        }
    }
}

void printPath(const vector<size_t> &pre) {
    stack<string> path;
    size_t p = goal;
    float weight_sum = 0;

    while (p != start) {
        auto u = pre[p];

        ostringstream oss;
        oss << setw(2) << u << " to " << setw(2) << p << " ("
            << road_name[to_string(u) + "..." + to_string(p)]
            << ")";
        path.push(oss.str());

        weight_sum += adj_list[u][p];
        p = u;
    }


    cout << "Weight sum: " << weight_sum << '\n';
    while (!path.empty()) {
        cout << path.top() << '\n';
        path.pop();
    }
    cout << '\n';
}

void pop(vector<size_t> &heap, vector<float> &d, unordered_map<size_t, size_t> &index) {
    auto v = heap.back();
    heap.pop_back();

    size_t parent = 1;
    while (parent * 2 < heap.size()) {
        auto child = parent * 2;
        if (child < heap.size() - 1 and d[heap[child + 1]] < d[heap[child]])
            ++child;
        if (d[v] <= d[heap[child]]) break;
        heap[parent] = heap[child];
        index[heap[parent]] = parent;
        parent = child;
    }
    heap[parent] = v;
    index[v] = parent;
}

void update(vector<size_t> &heap, vector<float> &d, unordered_map<size_t, size_t> &index, size_t v) {
    auto i = index[v];
    if (i == 0) {
        heap.push_back(v);
        i = heap.size() - 1;
    }

    auto parent = i / 2;
    while (parent > 0 and d[heap[parent]] > d[v]) {
        heap[i] = heap[parent];
        index[heap[i]] = i;
        i = parent;
        parent = i / 2;
    }
    heap[i] = v;
    index[v] = i;
}

void readFile(const char *fileName) {
    ifstream in(fileName);

    if (!in) {
        cout << "Fail";
        return;
    }

    in >> start >> goal;
    in >> V >> E;
    in.ignore();

    adj_list.resize(V);


    for (int i = 0; i < E; ++i) {
        string line;
        getline(in, line);
        getDataFromLine(line);
    }


}

void getDataFromLine(const string &line) {
    string token;
    vector<string> tokens;
    for (istringstream iss(line); getline(iss, token, ' '); tokens.push_back(token)) {}

    auto u = static_cast<size_t>(stoi(tokens[0]));
    auto v = static_cast<size_t>(stoi(tokens[1]));
    auto weight = stof(tokens[3]);
    adj_list[u][v] = adj_list[v][u] = weight;
    road_name[tokens[0] + "..." + tokens[1]] = tokens[2];
    road_name[tokens[1] + "..." + tokens[0]] = tokens[2];
}

template<typename _Container>
void find_path() {
    _Container container;
    container.push(start);

    vector<bool> visited(V, false);
    visited[start] = true;
    vector<size_t> pre(V, 0);


    while (!container.empty()) {
        auto current = container.top();

        if (current == goal) {
            printPath(pre);
            return;
        }

        container.pop();

        for (const auto &adj_vertex : adj_list[current]) {
            auto v = adj_vertex.first;

            if (!visited[v]) {
                pre[v] = current;
                container.push(v);
                visited[v] = true;
            }
        }
    }
}