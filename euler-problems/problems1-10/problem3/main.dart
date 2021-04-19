
/**
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 * Result: 6857
 */

int solve1() {
  int n = 600851475143;
  int i = 2;

  while (n > 1) {
    while (n % i != 0) {
      i++;
    }
    n ~/= i;
  }

  return i;
}

int _recursive(i, n) =>
    n <= 1 ? i : n % i != 0 ? _recursive(i + 1, n) : _recursive(i, n ~/ i);

int solve2() {
  int n = 600851475143;
  return _recursive(2, n);
}

main(List<String> arguments) {
  print(solve1());
  print(solve2());
}
