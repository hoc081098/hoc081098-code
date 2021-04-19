//
// Created by Peter Hoc on 26/03/2018.
//

#ifndef GRAPH_TRAVERSAL_GRAPH_H
#define GRAPH_TRAVERSAL_GRAPH_H

#include <iostream>
#include <fstream>
#include "linked_list.h"

namespace petrus {
    class graph {

        linked_list<linked_list<int>> adjacency_list;
        bool **adjacency_matrix;
        size_t V;
        size_t E;

        bool **alloc_matrix(int m, int n);

        void free_matrix(bool **&matrix, int m);

        void print_matrix() const;

        void initialize();

    public:
        void set_djacency_list(const linked_list<linked_list<int>> &adjacency_list);

        explicit graph(const linked_list<linked_list<int>> &adjacency_list);

        template<typename _Sequence>
        void traversal(int start_vertex, bool use_adjacency_list = true, std::ostream &os = std::cout) {
            _Sequence sequence;
            sequence.push(start_vertex);

            auto visited = new bool[V];
            for (int i = 0; i < V; ++i) {
                visited[i] = false;
            }
            visited[start_vertex] = true;

            os << '[';
            while (!sequence.is_empty()) {
                int cur = sequence.peek();
                sequence.pop();

                os << cur;

                if (use_adjacency_list) {
                    adjacency_list[cur].for_each([&](const int &adj) {
                        if (!visited[adj]) {
                            sequence.push(adj);
                            visited[adj] = true;
                        }
                    });
                } else {
                    for (int adj = 0; adj < V; ++adj) {
                        if (adjacency_matrix[cur][adj] && !visited[adj]) {
                            sequence.push(adj);
                            visited[adj] = true;
                        }
                    }
                }

                os << (!sequence.is_empty() ? "..." : "]\n");
            }
        }

        virtual ~graph();
    };
}


#endif //GRAPH_TRAVERSAL_GRAPH_H