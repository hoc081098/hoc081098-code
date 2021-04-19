import 'package:quiver/iterables.dart';

/*
The number 3797 has an interesting property. Being prime itself, 
it is possible to continuously remove digits from left to right, 
and remain prime at each stage: 3797, 797, 97, and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
Result: 748317
 */

final pr = {};

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

solve() => truncatablePrimes.take(11).reduce((acc, e) => acc + e);

Iterable get truncatablePrimes sync* {
  var i = 11;
  while (true) {
    if (check(i)) {
      yield i;
    }
    ++i;
  }
}

bool check(final int i) {
  var j = i;
  while (j != 0) {
    if (!isPrime(j)) {
      return false;
    }
    j ~/= 10;
  }

  final s = i.toString();
  return range(1, s.length)
      .map((i) => s.substring(i))
      .map(int.parse)
      .every(isPrime);
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}

//****************************
// 748317
// Executed in 246ms
//****************************
