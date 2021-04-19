/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c},
there are exactly three solutions for p = 120.
{20,48,52}, {24,45,51}, {30,40,50}
For which value of p ≤ 1000, is the number of solutions maximised?
Result: 840
 */

solve() {
  var max = 3;
  var countOfMax = countSolutions(max);
  for (int i = 4; i <= 1000; i++) {
    var countOfI = countSolutions(i);
    if (countOfI > countOfMax) {
      countOfMax = countOfI;
      max = i;
    }
  }
  return max;
}

int countSolutions(num e) {
  var count = 0;
  final q = e.toInt();
  for (int a = 1; a < (q >> 1); a++) {
    for (int b = a; b < (q >> 1); b++) {
      final c = q - a - b;
      if (c <= b) continue;
      if (a * a + b * b == c * c) {
        ++count;
      }
    }
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
// 840
// Executed in 74ms
//****************************
