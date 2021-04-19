/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?

Result: 73682
*/

const currency = const [1, 2, 5, 10, 20, 50, 100, 200];
const n = 200;

solve() => count(currency.length, n);

int count(int length, int n) {
  if (n == 0) {
    return 1;
  }
  if (n < 0) {
    return 0;
  }
  if (length <= 0) {
    return 0;
  }
  return count(
          length, n - currency[length - 1]) /*include currency[length - 1]*/ +
      count(length - 1, n); /*exclude currency[length - 1]*/
}

main(List<String> arguments) {
  print(solve());
}
