/**
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * Result: 906609
 */

fun solve1(): Int {
    var max = 0
    for (i in 100 until 1000) {
        for (j in 100 until 1000) {
            val num = i * j
            if (isPalindromic(num)) {
                max = maxOf(max, num)
            }
        }
    }
    return max
}

fun solve2() = (100 until 1000).flatMap { i ->
    (100 until 1000).map { it * i }
}.filter(::isPalindromic).max() ?: 0

fun isPalindromic(num: Int): Boolean {
    val s = num.toString()
    return s == s.reversed()
}

fun main(args: Array<String>) {
    println(solve1())
    println(solve2())
}