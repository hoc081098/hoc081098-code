#include <iostream>
using namespace std;

//
//

int fibonacci_tailrec(int n, int pre, int cur) {
  if (n == 0) return pre;
  return fibonacci_tailrec(n - 1, cur, pre + cur);
}

int fibonacci1(int n) {
  return fibonacci_tailrec(n, 0, 1);
}

//
//

int fibonacci2(int n) {
  if (n <= 1) return n;
  return fibonacci2(n - 1) + fibonacci2(n - 2);
}

//
//

int fibonacci3(int n) {
  if (n <= 1) return n;
  int f1 = 1, f2 = 1;
  
  for (int i = 2; i <= n; i++) {
    int temp = f1 + f2;
    f1 = f2;
    f2 = temp;
  }
  
  return f1;
}

int main() {
  cout << fibonacci3(70) << ' ' << fibonacci1(70);
}
