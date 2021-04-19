/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?

Result: 40C20 === 137846528820
 */

factorial(n) =>
    new Iterable.generate(n - 1, (i) => i + 2).reduce((acc, e) => acc * e);

solve() {
  final n = 40;
  final k = 20;
  return factorial(n) ~/ (factorial(k) * factorial(n - k));
}

main(List<String> arguments) {
  print(solve());
}
