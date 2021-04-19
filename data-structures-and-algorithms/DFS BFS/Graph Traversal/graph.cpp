//
// Created by Peter Hoc on 26/03/2018.
//

#include "graph.h"

petrus::graph::graph(const linked_list<linked_list<int>> &adjacency_list)
        : adjacency_list(adjacency_list), adjacency_matrix(NULL) {
    initialize();
}

void petrus::graph::print_matrix() const {
    for (int j = 0; j < V; ++j) {
        for (int k = 0; k < V; ++k) {
            std::cout << adjacency_matrix[j][k] << ' ';
        }
        std::cout << '\n';
    }
}

bool **petrus::graph::alloc_matrix(int m, int n) {
    auto matrix = new bool *[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new bool[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = false;
        }
    }
    return matrix;
}

void petrus::graph::free_matrix(bool **&matrix, int m) {
    if (matrix == NULL) return;

    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
        matrix[i] = NULL;
    }
    delete[] matrix;
    matrix = NULL;
}

petrus::graph::~graph() {
    free_matrix(adjacency_matrix, V);
}

void petrus::graph::set_djacency_list(const petrus::linked_list<petrus::linked_list<int>> &adjacency_list) {
    this->adjacency_list = adjacency_list;
    adjacency_matrix = NULL;
    initialize();
}

void petrus::graph::initialize() {
    if (adjacency_list.size() == 0) {
        free_matrix(adjacency_matrix, V);
        throw std::invalid_argument("Adjacency list's size must be positive");
    }

    V = adjacency_list.size();
    E = 0;
    free_matrix(adjacency_matrix, V);
    adjacency_matrix = alloc_matrix(V, V);

    int i = 0;
    adjacency_list.for_each([&](const linked_list<int> &e) {
        E += e.size();
        e.for_each([&](const int &v) {
            adjacency_matrix[i][v] = true;
        });
        ++i;
    });
#ifdef DEBUG
    print_matrix();
#endif
}

