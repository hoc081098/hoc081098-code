import 'dart:math' show pow;

/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

Result: 443839
*/

/*
10^(d - 1) <= d * 9^5 < 10^d
=>d = 6
*/

bool valid(n, p) {
  var sum = 0;
  for (var t = n; t != 0; sum += p[t % 10], t ~/= 10);
  return sum == n;
}

Iterable range(start, end) =>
    new Iterable.generate(end - start, (i) => i + start);

solve() {
  final p = {0: 0};
  for (var i = 1; i < 10; i++) {
    p[i] = pow(i, 5);
  }

  return range(2, 6 * p[9] + 1)
      .where((i) => valid(i, p))
      .reduce((a, e) => a + e);
}

main(List<String> arguments) {
  print(solve());
}
