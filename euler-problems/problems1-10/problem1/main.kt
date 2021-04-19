/**
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 * The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 * Result: 233168
 */

fun solve1(): Int {
    var sum = 0
    for (i in 0 until 1000) {
        if (i % 5 == 0 || i % 3 == 0) {
            sum += i
        }
    }
    return sum
}

fun solve2(): Int {
    return (0 until 1000).filter { it % 3 == 0 || it % 5 == 0 }.sum()
}

fun solve3(): Int {
    return (0 until 1000).sumBy {
        if (it % 3 == 0 || it % 5 == 0) it
        else 0
    }
}

fun solve4(): Int {
    //sum_3or5(n) = sum_3(n) + sum_5(n) - sum_15(n)
    //sum_k(n) = sum (ik), i in 0 to (n - 1) / k
    fun sum(k: Int, n: Int): Int {
        return (0..(n - 1) / k).sumBy { k * it }
    }
    return sum(3, 1000) + sum(5, 1000) - sum(15, 1000)
}

fun main(args: Array<String>) {
    println(solve1())
    println(solve2())
    println(solve3())
    println(solve4())
}