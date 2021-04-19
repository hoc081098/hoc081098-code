import 'package:quiver/iterables.dart' as quiver_iter;
import 'package:collection/collection.dart' show IterableEquality;

/*
The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)
Result: 872187
 */

const int max = 1000000;
final eq = const IterableEquality().equals;

solve() {
  return quiver_iter
      .range(1, max)
      .where(isPalindromicInBothBases)
      .reduce((acc, e) => acc + e);
}

bool isPalindromicInBothBases(num e) {
  final dec = e.toString().split('');
  final bin = toBin(e.toInt());
  return eq(dec, dec.reversed) && eq(bin, bin.toList().reversed);
}

Iterable toBin(int e) sync* {
  while (e != 0) {
    yield e & 1;
    e >>= 1;
  }
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}

//****************************
// 872187
// Executed in 563ms
//****************************