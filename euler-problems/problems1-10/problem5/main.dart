/**
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 * Result: 232792560
 */


int gcd(int a, int b) => b == 0 ? a : gcd(b, a % b);

int lcm(int a, int b) => (a * b) ~/ gcd(a, b);

Iterable<int> int_range(int start, int end) sync* {
  for (int i = start; i < end; i++) {
    yield i;
  }
}

int solve() => int_range(1, 21).reduce(lcm);

main(List<String> arguments) {
  print(solve());
}
