/**
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 * The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 * Result: 233168
 */

int solve1() {
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}

int solve2() {
  final sum = new Iterable.generate(1000)
      .where((i) => i % 3 == 0 || i % 5 == 0)
      .reduce((acc, e) => acc + e);
  return sum;
}

int solve3() {
  //sum_3or5(n) = sum_3(n) + sum_5(n) - sum_15(n)
  //sum_k(n) = sum (ik), i in 0 to (n - 1) / k
  final sum = (k, n) =>
      new Iterable.generate((n - 1) ~/ k + 1).reduce((acc, i) => acc + k * i);
  return sum(3, 1000) + sum(5, 1000) - sum(15, 1000);
}

main(List<String> arguments) {
  print(solve1());
  print(solve2());
  print(solve3());
}
