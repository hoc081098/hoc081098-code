/*
The Fibonacci sequence is defined by the recurrence relation:
    Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144
The 12th term, F12, is the first term to contain three digits.
What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

Result: 4782
*/

class Pair<T, R> {
  final T first;
  final R second;

  Pair(this.first, this.second);

  @override
  String toString() => 'Pair{ $first, $second }';
}

Iterable<Pair<int, int>> get fibonacciSequenceWithIndex sync* {
  var f = 1;
  var f1 = 1;
  var f2 = 1;
  var index = 2;

  yield new Pair(1, 1);
  while (true) {
    yield new Pair(f, index++);
    f = f1 + f2;
    f1 = f2;
    f2 = f;
  }
}

int solve() => fibonacciSequenceWithIndex
      .firstWhere((pair) => pair.first.toString().length >= 1000)
      .second;

main(List<String> arguments) {
  print(solve());
}
