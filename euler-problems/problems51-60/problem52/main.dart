import 'dart:math' as math;
import 'package:collection/collection.dart';
import 'package:collection/src/algorithms.dart';
import 'package:quiver/iterables.dart';

/*
  It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits,
  but in a different order.
  Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
  Result: 142857
*/

final eq = const ListEquality().equals;

bool isSameDigits(int n, Iterable<int> others) {
  final q = n.toString().split('')..sort();
  return others.every((i) => eq(q, i.toString().split('')..sort()));
}

solve() {
  final iterable = new Iterable.generate(5, (i) => i + 2);

  return generate(() => 1, (i) => i + 1).firstWhere((int e) {
    return isSameDigits(e, iterable.map((i) => i * e));
  });
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}

//****************************
// 142857
// Executed in 162ms
//****************************
