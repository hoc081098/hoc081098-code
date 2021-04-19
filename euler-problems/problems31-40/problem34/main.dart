import 'package:quiver/iterables.dart' as quiver_iter;

/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
Find the sum of all numbers which are equal to the sum of the factorial of their digits.
Note: as 1! = 1 and 2! = 2 are not sums they are not included.
Result: 40730
*/

/*
10^(d-1) <= 9! * d < 10^d
<=> d - 1 <= log_10(9! * d) < d
<=> d = 7
*/

solve() {
  final factorials = {0: 1};
  var f = 1;
  quiver_iter.range(1, 10).forEach((i) {
    f *= i;
    factorials[i] = f;
  });
  return quiver_iter
      .range(3, factorials[9] * 7 + 1)
      .where((e) => test(e, factorials))
      .reduce((acc, e) => acc + e);
}

bool test(final elem, factorials) {
  var sum = 0, temp = elem;
  while (temp != 0) {
    sum += factorials[temp % 10];
    temp ~/= 10;
  }
  return sum == elem;
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}
