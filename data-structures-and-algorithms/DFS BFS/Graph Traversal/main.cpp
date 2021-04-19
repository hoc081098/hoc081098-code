#include <iostream>
#include "linked_list.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

int main() {
    try {
        petrus::linked_list<petrus::linked_list<int>> adj_list = {
                {1, 2, 3, 4},
                {2, 3, 5},
                {4},
                {1},
                {3},
                {3, 4, 2},
        };
        petrus::graph g(adj_list);
        std::cout << "DFS: ";
        g.traversal<petrus::stack<int>>(0);
        std::cout << "BFS: ";
        g.traversal<petrus::queue<int>>(0);


        g.set_djacency_list({{1, 2},
                             {2, 3, 4},
                             {5, 6},
                             {},
                             {},
                             {},
                             {}});

        std::cout << "DFS: ";
        g.traversal<petrus::stack<int>>(0);
        std::cout << "BFS: ";
        g.traversal<petrus::queue<int>>(0);
    } catch (...) {
        std::cout << "Error occurred. Exit...";
    }

    return 0;
}