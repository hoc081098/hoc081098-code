import 'dart:math' show max;

/**
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * Result: 906609
 */

bool is_palindromic(int n) {
  final s = n.toString();
  final reversed = s.split('').reversed.join();
  return reversed == s;
}

int solve1() {
  int m = 0;
  for (int i = 100; i <= 999; i++) {
    for (int j = 100; j <= 999; j++) {
      final num = i * j;
      if (is_palindromic(num)) {
        m = max(m, num);
      }
    }
  }
  return m;
}

Iterable<int> int_range(int start, int end) sync* {
  for (int i = start; i < end; i++) {
    yield i;
  }
}

int solve2() {
  var range = int_range(100, 1000);
  return range
      .expand((i) => range.map((j) => i * j))
      .where(is_palindromic)
      .reduce(max);
}

main(List<String> arguments) {
  print(solve1());
  print(solve2());
}
