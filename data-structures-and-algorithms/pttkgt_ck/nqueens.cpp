//
// Created by Peter Hoc on 22/05/2018.
//

#include <iostream>
#include <iomanip>

using namespace std;

const int N = 8;
int a[N], count = 0;
bool cols[N], left_diagonal[2 * N - 1], right_diagonal[2 * N - 1];

void print_solution() {
    cout << setw(3) << ++count << ". ";
    for (int i = 0; i < N; i++)
        cout << setw(2) << a[i] + 1 << ' ';
    cout << '\n';
}

void put_queen(int row) {
    for (int col = 0; col < N; col++) {
        if (cols[col]
            || left_diagonal[row + col]
            || right_diagonal[row - col + N - 1])
            continue;

        cols[col]
                = left_diagonal[row + col]
                = right_diagonal[row - col + N - 1]
                = true;

        a[row] = col;
        if (row < N - 1) put_queen(row + 1);
        else print_solution();

        cols[col]
                = left_diagonal[row + col]
                = right_diagonal[row - col + N - 1]
                = false;
    }
}

int main() {
    put_queen(0);
}