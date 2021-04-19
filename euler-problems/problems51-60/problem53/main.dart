import 'dart:math' as math;
import 'package:collection/collection.dart';
import 'package:collection/src/algorithms.dart';
import 'package:quiver/iterables.dart';

/*
  There are exactly ten ways of selecting three from five, 12345:
  123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
  In combinatorics, we use the notation, 5C3 = 10.
  In general,
  nCr =	n! / (r!(n−r)!), where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
  It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
  How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?
  Result: 4075
*/

//int factorial(int n) {
//  var f = 1;
//  for (var i = 2; i <= n; i++) {
//    f *= i;
//  }
//  return f;
//}
//
//int nCr(int n, int r) {
//  return factorial(n) ~/ (factorial(r) * factorial(n - r));
//}

const max = 100;

final help = new List.generate(max + 1, (i) => new List.filled(i, 0));

int nCr(int n, int r) {
  if (r == 0 || r == n) {
    return 1;
  }
  if (help[n][r] > 0) {
    return help[n][r];
  }
  return help[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

solve() {
  var c = 0;
  for (var n = 1; n <= max; n++) {
    for (var r = 1; r < n; r++) {
      if (nCr(n, r) > 1000000) ++c;
    }
  }
  return c;
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}

//****************************
// 4075
// Executed in 9ms
//****************************
