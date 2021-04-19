/**
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 * Result: 142913828922
 */

const maxNum = 2000000;

int solve() {
  final is_prime = new List.filled(maxNum, true);
  is_prime[2] = true;

  for (int i = 2; i * i <= maxNum; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < maxNum; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int sum = 0;
  for (int i = 2; i < maxNum - 1; i++) {
    if (is_prime[i]) {
      sum += i;
    }
  }
  return sum;
}

main(List<String> arguments) {
  print(solve());
}
