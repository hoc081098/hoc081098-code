import java.text.DecimalFormat
import kotlin.system.measureNanoTime

/**
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 * Result: 6857
 */

fun solve1(): Int {
    var n = 600851475143L
    var i = 2

    while (n > 1) {
        while (n % i != 0L) {
            i++
        }
        n /= i
    }

    return i
}

fun solve2(): Int {
    tailrec fun helper(n: Long, i: Int): Int = when {
        n <= 1 -> i
        n % i != 0L -> helper(n, i + 1)
        else -> helper(n / i, i)
    }

    val n = 600851475143L
    return helper(n, 2)
}


fun main(args: Array<String>) {
    measureNanoTime { println(solve1()) }.let { println("solve1: ${DecimalFormat.getInstance().format(it)}") }
    measureNanoTime { println(solve2()) }.let { println("solve2: ${DecimalFormat.getInstance().format(it)}") }
}