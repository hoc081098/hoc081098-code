/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.
What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

Result: 669171001
*/

const n = 1001;

solve() {
  var list = new List.generate(n, (_) => new List.filled(n, 0));

  var count = n * n;
  var L = 0;
  var R = n - 1;
  var T = 0;
  var B = n - 1;

  var sum = 0;
  while (count > 0) {
    for (var i = R; i >= L; i--) {
      list[T][i] = count--;
      if (T == i || T + i == n - 1) {
        sum += list[T][i];
      }
    }
    ++T;

    for (var i = T; i <= B; i++) {
      list[i][L] = count--;
      if (L == i || L + i == n - 1) {
        sum += list[i][L];
      }
    }
    ++L;

    for (var i = L; i <= R; i++) {
      list[B][i] = count--;
      if (B == i || B + i == n - 1) {
        sum += list[B][i];
      }
    }
    --B;

    for (var i = B; i >= T; i--) {
      list[i][R] = count--;
      if (R == i || R + i == n - 1) {
        sum += list[i][R];
      }
    }
    --R;
  }

  return sum;
}

main(List<String> arguments) {
  print(solve());
}
