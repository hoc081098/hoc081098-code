import 'dart:math' show pow;

/**
 *The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 * Result: 25164150
 */

sum(a, b) => a + b;

int solve1() {
  final fun1 =
      (n) => new Iterable.generate(n + 1).map((i) => i * i).reduce(sum);
  final fun2 = (n) {
    final s = new Iterable.generate(n + 1).reduce(sum);
    return s * s;
  };
  return (fun1(100) - fun2(100)).abs();
}

int solve2() {
  // (1 + 2 + ... + n) ^ 2 = (n * (n + 1) / 2) ^ 2;
  // 1^2 + 2^2 + ... + n^2 = n * (n + 1) * (2n + 1) / 6;
  final fun1 = (n) => pow(n * (n + 1) ~/ 2, 2);
  final fun2 = (n) => n * (n + 1) * (2 * n + 1) ~/ 6;
  return (fun1(100) - fun2(100)).abs();
}

main(List<String> arguments) {
  print(solve1());
  print(solve2());
}
