//
// Created by Peter Hoc on 22/05/2018.
//
#include <iostream>
#include <iomanip>

using namespace std;

const int n = 2;
const int k = 4;
int a[k], count = 0;

void print() {
    cout << setw(3) << ++count << ". ";
    for (int i = 0; i < k; i++)
        cout << setw(3) << a[i] + 1 << ' ';
    cout << '\n';
}

void Try(int i) {
    for (int j = 0; j < n; j++) {
        a[i] = j;
        if (i < k - 1) Try(i + 1);
        else print();
    }
}

int main() {
    Try(0);
}