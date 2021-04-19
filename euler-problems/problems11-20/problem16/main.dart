/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
Result: 1366
*/

solve() {
  final n = 1 << 1000;
  return n.toString().split('').map(int.parse).reduce((acc, e) => acc + e);
}

main(List<String> arguments) {
  print(solve());
}
