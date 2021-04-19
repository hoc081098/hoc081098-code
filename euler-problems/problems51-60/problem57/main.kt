import java.math.BigInteger.*
import kotlin.system.measureTimeMillis
import java.math.BigInteger as BigInt

/*
    It is possible to show that the square root of two can be expressed as an infinite continued fraction.
    √ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
    By expanding this for the first four iterations, we get:
        1 + 1/2 = 3/2 = 1.5
        1 + 1/(2 + 1/2) = 7/5 = 1.4
        1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
        1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
    The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985,
        is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
    In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
    Result: 153
*/



tailrec fun gcd(a: BigInt, b: BigInt): BigInt =
        if (b == ZERO) a else gcd(b, a % b)

fun reduce(p: Pair<BigInt, BigInt>) =
        gcd(p.first, p.second).let {
            p.first / it to p.second / it
        }

fun solve(): Any? {
    var num = ZERO
    var den = ONE
    var r = 0

    repeat(1_000) {
        val (newNum, newDen) = reduce(den to den * TWO + num)
        num = newNum
        den = newDen

        val (a, b) = reduce(num + den to den)
        if (a.toString().length > b.toString().length) {
            ++r
        }
    }

    return r
}

fun otherSolution(): Any? {
    return generateSequence(3.toBigInteger() to TWO) { (n, d) ->
        val num = n - d
        val den = d
        val t = den * TWO + num
        reduce(den + t to t)
    }.take(1_000).count { (n, d) ->
        n.toString().length > d.toString().length
    }
}

fun main(args: Array<String>) {
    measureTimeMillis {
        println(otherSolution())
    }.let { println("Executed in ${it}ms") }
    measureTimeMillis {
        println(solve())
    }.let { println("Executed in ${it}ms") }

}

//153
//Executed in 433ms
//153
//Executed in 515ms