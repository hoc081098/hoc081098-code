//
// Created by Peter Hoc on 22/05/2018.
//
#include <iostream>
#include <iomanip>

using namespace std;

const int n = 5;
bool used[n];
int a[n], count = 0;

void print() {
    cout << setw(3) << ++count << ". ";
    for (int i = 0; i < n; i++)
        cout << setw(3) << a[i] + 1 << ' ';
    cout << '\n';
}

void Try(int i) {
    for (int j = 0; j < n; j++) {
        if (used[j]) continue;

        used[j] = true;

        a[i] = j;
        if (i < n - 1) Try(i + 1);
        else print();

        used[j] = false;
    }
}

int main() {
    Try(0);
}