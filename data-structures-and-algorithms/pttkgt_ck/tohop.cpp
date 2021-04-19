//
// Created by Peter Hoc on 22/05/2018.
//

#include <iostream>
#include <iomanip>

using namespace std;

const int n = 9;
const int k = 4;
int a[k + 1], count = 0;

void print() {
    cout << setw(3) << ++count << ". ";
    for (int i = 1; i <= k; i++)
        cout << setw(3) << a[i] << ' ';
    cout << '\n';
}

void Try(int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i < k) Try(i + 1);
        else print();
    }
}

int main() {
    a[0] = 0;
    Try(1);
}