import 'dart:math';
import 'package:quiver/iterables.dart' as quiver_iter;
/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
How many circular primes are there below one million?
Result: 55
 */

const int max = 1000000;

solve() {
  final isPrime = new List.filled(max + 1, true);
  for (int i = 2; i * i <= max; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= max; j += i) {
        isPrime[j] = false;
      }
    }
  }

  return quiver_iter
      .range(2, max)
      .where((i) => isCircularPrime(i, isPrime))
      .length;
}

Iterable<int> rotations(int n) sync* {
  var temp = n, i = n;
  final power = pow(10, n.toString().length - 1);

  while (i != 0) {
    yield temp;
    temp = (temp % 10) * power + temp ~/ 10;
    i ~/= 10;
  }
}

/*
Slower
Iterable<int> rotations(int n) sync* {
  final list = n.toString().split('').map(int.parse);
  final length = list.length;
  final cycle =
      quiver_iter.cycle(list).take(length * 2 - 1).toList(growable: false);

  for (int i = 0; i < length; i++) {
    yield cycle.getRange(i, i + length).reduce((a, e) => a * 10 + e);
  }
}*/

bool isCircularPrime(num i, List<bool> isPrime) {
  return rotations(i).every((e) => isPrime[e]);
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}
