//
// Created by Peter Hoc on 22/05/2018.
//

#include <iostream>

using namespace std;

bool solve(const int a[], int n, int sum);

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof a / sizeof *a;
    int sum = 14;
    cout << boolalpha << solve(a, n, sum);
}

bool solve(const int a[], int n, int sum) {
    if (n == 0 or sum < 0) return false;

    // dp[i][j] = true if sum j is possible
    // with array elements from 0 to i.
    bool **dp = new bool *[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new bool[sum + 1];
        fill(dp[i] + 1, dp[i] + sum + 1, false);
        dp[i][0] = true;
    }
    if (a[0] <= sum) dp[0][a[0]] = true;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            dp[i][j] = a[i] <= j
                       ? dp[i - 1][j] or dp[i - 1][j - a[i]] // exclude or include
                       : dp[i - 1][j];                       // exclude
        }
    }

    return dp[n - 1][sum];
}
