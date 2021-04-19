import kotlin.system.measureTimeMillis

/*
    A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros.
    Despite their size, the sum of the digits in each number is only 1.
    Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
    Result: 972
 */

fun main(args: Array<String>) = measureTimeMillis {
    val range = 1 until 100
    range.flatMap {
        val a = it.toBigInteger()
        range.map {
            a.pow(it).toString().sumBy { it - '0' }
        }
    }.max()?.let(::println)
}.let { println("Executed in ${it}ms") }

// 972
// Executed in 203ms