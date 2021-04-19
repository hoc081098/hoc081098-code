#include <vector>
#include <iostream>
 
//knapsack problem
//C++14 clang 4.0
 
struct item {
  int weight;
  int value;
};
 
 
void solve(const std::vector<item>& a, int M) {
  const int n = a.size();
 
  std::vector<std::vector<int>> dp (n + 1, std::vector<int>(M + 1, 0));
  std::vector<std::vector<int>> s (n + 1, std::vector<int>(M + 1, 0));
 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= M; j++) {
      if (a[i - 1].weight > j) {
        dp[i][j] = dp[i - 1][j];
        s[i][j] = 0;
      } else {
        for (int k = 1; k <= j / a[i - 1].weight; k++) {
          int new_max_val = dp[i - 1][j - k * a[i - 1].weight] + k * a[i - 1].value;
          if (new_max_val > dp[i][j]) {
            dp[i][j] = new_max_val;
            s[i][j] = k;
          };
        }
      }
    }
  }
 
  std::cout << "Max weight: " << M << '\n';
  std::cout << "Max value: " << dp[n][M] << '\n';
 
  for (int i = n; i > 0; i--) {
    if (s[i][M]) {
      std::cout << "Select " << s[i][M] << " item " << (i - 1)
                << " (weight: " << a[i - 1].weight << ", value: " << a[i - 1].value << ")\n";
      M -= s[i][M] * a[i - 1].weight;
    }
  }
}
 
int main() {
  std::vector<item> items {
    {3, 4},
    {4, 5},
    {5, 6},
    {2, 3},
    {1, 1}
  };
 
  const int M = 13;
 
  solve(items, M);
}
