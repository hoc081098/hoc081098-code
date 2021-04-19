import 'package:quiver/iterables.dart';
/*
  An irrational decimal fraction is created by concatenating the positive integers:
  0.12345678910[1]112131415161718192021...
  It can be seen that the 12th digit of the fractional part is 1.
  If dn represents the nth digit of the fractional part, find the value of the following expression.
  d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
  Result: 210
 */

final Iterable<String> iterable = generate(() => 1, (i) => i + 1)
    .expand<String>((i) => i.toString().split(''));

solve() {
  return generate(() => 1, (i) => i * 10)
      .takeWhile((i) => i <= 1000000)
      .map((i) => iterable.elementAt(i - 1))
      .map(int.parse)
      .reduce((acc, e) => acc * e);
}

main(List<String> arguments) {
  final s = new Stopwatch()..start();
  print(solve());
  s.stop();
  print("Executed in ${s.elapsedMilliseconds}ms");
}

//****************************
// 210
// Executed in 98ms
//****************************
