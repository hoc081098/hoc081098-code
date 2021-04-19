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

void prim(int start_vertex) {
    int *k = new int[n];
    fill(k, k + n, maxW);

    int *pre = new int[n];
    fill(pre, pre + n, NIL);

    bool *visited = new bool[n];
    fill(visited, visited + n, false);

    k[start_vertex] = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_vertex = NIL;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (min_vertex == NIL || k[i] < k[min_vertex]) {
                    min_vertex = i;
                }
            }
        }

        visited[min_vertex] = true;

        for (int v = 0; v < n; ++v) {
            if (weight_matrix[min_vertex][v] == 0
                || visited[v]                     
                || k[v] <= weight_matrix[min_vertex][v])
                continue;
            //relax
            k[v] = weight_matrix[min_vertex][v];
            pre[v] = min_vertex;
        }
    }
   
    int weight_sum = 0;
    cout << "Mimimum spanning tree\n";
    cout << "Edege ... Weight\n";
    for (int v = 1; v < n; v++) {
        cout << pre[v] << " - " << v << " ... " << k[v] << '\n';
        weight_sum += k[v];
    }
    
    cout << "Weight sum: " << weight_sum << '\n';
}

int main() {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (weight_matrix[i][j] > max) max = weight_matrix[i][j];
        }
    }
    maxW = (n - 1) * max;

    prim(0);
}
