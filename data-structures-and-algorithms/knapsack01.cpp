#include <vector>
#include <iostream>
 
 
//knapsack 0-1
//C++14 clang 4.0
 
 
struct item {
  int weight;
  int value;
};
 
void solve(const std::vector<item>& a, int M) {
  const int n = a.size();
 
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(M + 1, 0));
 
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= M; j++) {
      if (a[i - 1].weight > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - a[i - 1].weight] + a[i - 1].value);
    }
  }
  std::cout << "Max weight: " << M << '\n';
  std::cout << "Max value: " << dp[n][M] << '\n';
  for (int i = n; i > 0; i--) {
    if (dp[i][M] != dp[i - 1][M]) {
      std::cout << "Select " << (i - 1) << " (value: " << a[i - 1].value
                << ", weight: " << a[i - 1].weight << ")\n";
      M -= a[i - 1].weight;
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
