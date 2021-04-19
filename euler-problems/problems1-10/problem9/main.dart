/**
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 *
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 * Result: 31875000
 */

int solve() {
  for (int i = 1; i < 1000; i++) {
    for (int j = 1; j < 1000; j++) {
      final k = 1000 - i - j;
      if (i * i + j * j == k * k) {
        return i * j * k;
      }
    }
  }
  return -1;
}

main(List<String> arguments) {
  print(solve());
}
