//
// Created by Peter Hoc on 22/05/2018.
//
#include <algorithm>
#include <iostream>

using namespace std;

static const int NIL = -1;
static const int n = 4;

int maxW;
int weight_matrix[n][n] = {
        {0, 1,   0, 900},
        {1, 0,   1, 0},
        {0, 123, 0, 412},
        {1, 1,   1, 0}
};

void dijkstra(int start_vertex, int end_vertex) {
    int *d = new int[n];
    fill(d, d + n, maxW);

    int *pre = new int[n];
    fill(pre, pre + n, NIL);

    bool *visited = new bool[n];
    fill(visited, visited + n, false);

    d[start_vertex] = 0;

    while (true) {
        int min_vertex = NIL;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (min_vertex == NIL || d[i] < d[min_vertex]) {
                    min_vertex = i;
                }
            }
        }
        if (min_vertex == NIL // all vertex are visited
            || d[min_vertex] >= maxW) { // distance from start to min_vertex is infinity
            cout << "Oop! No path from " << start_vertex
                 << " to " << end_vertex << '\n';
            return;
        }
        if (min_vertex == end_vertex) {
            cout << "Path's length: " << d[min_vertex] << '\n';
            while (min_vertex != NIL) {
                cout << min_vertex
                     << (pre[min_vertex] != NIL ? " <- " : "");
                min_vertex = pre[min_vertex];
            }
            return;
        }

        visited[min_vertex] = true;

        for (int v = 0; v < n; ++v) {
            if (weight_matrix[min_vertex][v] == 0 // is not adjacency vertex
                || visited[v]                     // or already visited,  it means that  v is optimized
                || d[v] <= d[min_vertex] + weight_matrix[min_vertex][v]) // or current distance from start_vertex to v is still shortest
                continue;
            //relax
            d[v] = d[min_vertex] + weight_matrix[min_vertex][v];
            pre[v] = min_vertex;
        }
    }
}

int main() {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (weight_matrix[i][j] > max) max = weight_matrix[i][j];
        }
    }
    maxW = (n - 1) * max;

    dijkstra(0, n - 1);
}

