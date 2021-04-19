import 'dart:math';
import 'package:quiver/iterables.dart';

/*
  The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
  Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
  Result: 9110846700
*/

solve() {
  final w = pow(10, 10);
  return range(1, 1001).map((i) => pow(i, i)).reduce((acc, e) => (acc + e) % w);
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}

//****************************
// 9110846700
// Executed in 42ms
//****************************
