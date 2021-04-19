import 'dart:io';

/*
 Using names.txt (right click and 'Save Link/Target As...'),
 a 46K text file containing over five-thousand first names,
 begin by sorting it into alphabetical order.
 Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 What is the total of all the name scores in the file?
 Result: 871198282
*/

solve() {
  final val = (s) =>
      s.split('').map((c) => c.codeUnitAt(0) - 64).reduce((acc, e) => acc + e);
  final s = new File('./bin/p022_names.txt')
      .readAsStringSync()
      .split(new RegExp(r'\W+'))
      .where((s) => s.isNotEmpty)
      .toList(growable: false)
        ..sort();
  var result = 0;
  s.asMap().forEach((index, e) => result += (index + 1) * val(e));
  return result;
}

main(List<String> arguments) {
  print(solve());
}
