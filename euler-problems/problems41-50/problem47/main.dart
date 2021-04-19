import 'dart:math';
import 'package:quiver/iterables.dart';

/*
  The first two consecutive numbers to have two distinct prime factors are:
  14 = 2 × 7
  15 = 3 × 5
  The first three consecutive numbers to have three distinct prime factors are:
  644 = 2² × 7 × 23
  645 = 3 × 5 × 43
  646 = 2 × 17 × 19.
  Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
  Result: 134043
*/

solve() => generate(() => 1, (i) => i + 1)
    .firstWhere((i) => range(i, i + 4).every((e) => distinctPrimeFactors(e) == 4));

int distinctPrimeFactors(int e) {
  var i = 2;
  var count = 0;

  while (e > 1) {
    while (e % i != 0) ++i;
    while (e % i == 0) e ~/= i;
    ++count;
  }

  return count;
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}

//****************************
// 134043
// Executed in 7466ms
//****************************
