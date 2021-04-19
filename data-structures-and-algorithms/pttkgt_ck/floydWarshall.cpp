//
// Created by Peter Hoc on 25/05/2018.
//

#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

static const int n = 4;
static const int maxW = static_cast<int>(1e6);
int weight_matrix[n][n] = {
        {0,    1,   maxW, maxW},
        {1,    0,   1,    maxW},
        {maxW, 123, maxW, maxW},
        {1,    1,   1,    0}
};

int **newMatrix() {
    int **distance = new int *[n];
    for (int i = 0; i < n; ++i) {
        distance[i] = new int[n];
        copy(weight_matrix[i], weight_matrix[i] + n, distance[i]);
    }
    return distance;
}

void deleteMatrix(int **pInt) {
    for (int i = 0; i < n; ++i) {
        delete[] pInt[i];
    }
    delete[] pInt;
}

void floydWarshall() {
    int **distance = newMatrix();

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (distance[i][j] >= maxW) {
                cout << setw(6) << "INF";
            } else {
                cout << setw(6) << distance[i][j];
            }
        }
        cout << '\n';
    }

    deleteMatrix(distance);
}

int main() {
    floydWarshall();
}

