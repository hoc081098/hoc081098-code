import 'dart:math' show sqrt;

/**
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 * Result: 104743
 */

int solve1() {
  int n_th = 10001;
  int i = 0;
  int n = 2;

  while (true) {
    if (is_prime(n)) {
      ++i;
      if (i == n_th) {
        return n;
      }
    }
    ++n;
  }
}

bool is_prime(int n) =>
    n >= 2 &&
    new Iterable.generate(sqrt(n).floor() + 1).skip(2).every((i) => n % i != 0);

Iterable<int> get primes sync* {
  int i = 2;
  while (true) {
    if (is_prime(i)) {
      yield i;
    }
    ++i;
  }
}

int solve2() {
  int n_th = 10001;
  return primes.elementAt(n_th - 1);
}

main(List<String> arguments) {
  print(solve1());
  print(solve2());
}
