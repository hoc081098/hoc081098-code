import 'dart:math' as math;
import 'package:collection/src/algorithms.dart';
import 'package:quiver/iterables.dart';

/*
  The prime 41, can be written as the sum of six consecutive primes:
  41 = 2 + 3 + 5 + 7 + 11 + 13
  This is the longest sum of consecutive primes that adds to a prime below one-hundred.
  The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
  Which prime, below one-million, can be written as the sum of the most consecutive primes?
  Result: 997651
*/

solve() {
  const n = 1000000;
  final isPrime = new List.filled(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  final primes = range(2, n + 1).where((i) => isPrime[i]).toList();
  var t = 0;
  final sumPrime = [0]..addAll(primes.map((i) => t += i.toInt()));

  var m = -1;
  for (int i = 0; i < sumPrime.length; i++) {
    for (int j = 0; j < i - 1; j++) {
      final c = sumPrime[i] - sumPrime[j];
      if (c > n) {
        break;
      }
      if (binarySearch(primes, c) >= 0) {
        m = math.max(m, c);
      }
    }
  }
  return m;
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}

//****************************
// 997651
// Executed in 246ms
//****************************
