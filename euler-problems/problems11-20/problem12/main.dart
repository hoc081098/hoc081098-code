import 'dart:math' show sqrt;

/**
    The sequence of triangle numbers is generated by adding the natural numbers.
    So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

    Let us list the factors of the first seven triangle numbers:

    1: 1
    3: 1,3
    6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28
    We can see that 28 is the first triangle number to have over five divisors.

    What is the value of the first triangle number to have over five hundred divisors?

    Result: 76576500
 */

Iterable<int> get triangleNumbers sync* {
  var current = 1;
  var i = 1;
  while (true) {
    yield current;
    current += ++i;
  }
}

int solve() =>
    triangleNumbers.firstWhere((i) => countFactors(i) > 500, orElse: () => 0);

//int countFactors(int n) {
//  var count = 0;
//  for (int i = 2; i * i <= n; i++) {
//    if (n % i == 0) {
//      count += i * i < n ? 2 : 1;
//    }
//  }
//  return count;
//}

int countFactors(int n) {
  int s = sqrt(n).toInt();
  return new Iterable.generate(s - 1, (i) => i + 2)
      .where((i) => n % i == 0)
      .map((i) => i < s ? 2 : 1)
      .fold(0, (acc, e) => acc + e);
}

main(List<String> arguments) {
  print(solve());
}
