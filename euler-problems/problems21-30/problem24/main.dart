/*
A permutation is an ordered arrangement of objects.
 For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
 The lexicographic permutations of 0, 1 and 2 are:
 012   021   102   120   201   210
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 Result: 2783915460
 */

solve() {
  List<String> a = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];
  var count = 0;

  while (true) {
    ++count;
    if (count == 1000000) {
      return a.join();
    }

    int i = a.length - 2;
    for (; i >= 0; i--) {
      if (a[i].compareTo(a[i + 1]) < 0) {
        break;
      }
    }
    if (i < 0) {
      break;
    }

    int j = a.length - 1;
    for (; j > i; j--) {
      if (a[j].compareTo(a[i]) > 0) {
        break;
      }
    }

    //swap
    var temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    //reverse
    i = i + 1;
    j = a.length - 1;
    while (i < j) {
      var temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      ++i;
      --j;
    }
  }
}

main(List<String> arguments) {
  print(solve());
}
