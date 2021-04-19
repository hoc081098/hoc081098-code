/**
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 * Result: 232792560
 */

tailrec fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)

fun lcm(a: Long, b: Long) = (a * b) / gcd(a, b)

fun solve() = (1L..20L).reduce(::lcm)

fun main(args: Array<String>) {
    solve().let(::println)
}