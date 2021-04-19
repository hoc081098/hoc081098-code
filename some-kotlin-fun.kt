
import kotlin.coroutines.experimental.buildSequence

/**
 * Created by Peter Hoc on 03/08/2018
 */

// some util function for Iterable, List, CharSequence, String
// in spirit of Ruby

operator fun <T> List<T>.get(indices: Iterable<Int>) = slice(indices)

operator fun <T : Any> MutableList<T>.set(range: ClosedRange<Int>, from: Iterable<T>) {
    for (i in range.start..minOf(range.endInclusive, size - 1)) {
        removeAt(range.start)
    }
    addAll(range.start, from.toList())
}

fun <T> Iterable<Iterable<T>>.transpose(): List<List<T>> {
    if (count() == 0) return emptyList()
    require(map { it.count() }.toSet().size == 1) { "Element size difference!" }
    return first().mapIndexed { column, _ ->
        map { it.elementAt(column) }
    }
}

fun <T> Iterable<T>.eachCons(n: Int) = windowed(n)

fun <T> Iterable<T>.eachSlice(n: Int) = chunked(n)

fun <T> List<T>.rotated(n: Int) = when {
    n == 0 -> this
    n > 0 -> drop(n) + take(n)
    else -> takeLast(-n) + dropLast(-n)
}

inline fun <T> Iterable<T>.select(predicate: (T) -> Boolean) = filter(predicate)

inline fun <T> Iterable<T>.reject(predicate: (T) -> Boolean) = filterNot(predicate)

fun <T> Iterable<T>.cycle(n: Int) = (1..n).flatMap { this }

fun <T> Iterable<T>.cycle() = buildSequence {
    while (true) {
        yieldAll(this@cycle)
    }
}

inline val CharSequence.size get() = length

@Suppress("NOTHING_TO_INLINE")
inline operator fun <T> List<T>.component6() = get(6)

@Suppress("NOTHING_TO_INLINE")
inline operator fun <T> List<T>.component7() = get(7)

@Suppress("NOTHING_TO_INLINE")
inline operator fun <T> List<T>.component8() = get(8)

@Suppress("NOTHING_TO_INLINE")
inline operator fun <T> List<T>.component9() = get(9)

@Suppress("NOTHING_TO_INLINE")
inline operator fun <T> List<T>.component10() = get(10)

fun <T> Sequence<T>.join(separator: String = "") = joinToString(separator = separator)

fun <T> Iterable<T>.join(separator: String = "") = joinToString(separator = separator)

operator fun String.get(intRange: IntRange) = substring(intRange)

operator fun CharSequence.times(n: Int) = repeat(n)

inline val CharSequence.chars get() = toList()

operator fun Char.times(n: Int) = toString().times(n)

fun main(args: Array<String>) {
    val list = listOf(1, 2, 3, 4, 5, 6, 7, 8, 11, 2, 42, 234, 99)
    println(list.slice(listOf(1, 2, 3, 4)))
    println(list.slice(1..4))
    println(list.slice(1..6 step 2))

    println(
            listOf(
                    listOf(1, 2, 3, 4),
                    listOf(5, 11, 3, 4),
                    listOf(1, 123, 312, 4),
                    listOf(1, 2, 3, 4)
            ).transpose()
    )
    println('*' * 10)
    (1..2).eachCons(2).forEach(::println)
    println('*' * 10)
    (1..5).eachCons(10).forEach(::println)
    println('*' * 10)
    (1..10).eachCons(3).forEach(::println)
    println('*' * 10)

    println((1..100 step 3).eachCons(2) == (1..100 step 3).zipWithNext { a, b -> listOf(a, b) })

    (1..100).eachCons(2).all { (a, b) -> a < b }.let(::println)

    val (a, b, c, d, e, f, g, h) = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

    println('*' * 10)
    (1..2).eachSlice(2).forEach(::println)
    println('*' * 10)
    (1..5).eachSlice(10).forEach(::println)
    println('*' * 10)
    (1..10).eachSlice(3).forEach(::println)
    println('*' * 10)

    listOf(1).sorted()
    mutableListOf(1).sort()


    val p = listOf("a", "b", "c", "d")
    p.rotated(2).let(::println)      // => ["c", "d", "a", "b"]
    p.rotated(-3).let(::println)       // => ["b", "c", "d", "a"]
    p.rotated(1).let(::println)        // => ["b", "c", "d", "a"]
    p.rotated(-1).let(::println)       // => ["d", "a", "b", "c"]

    println((1..100).filter { it % 2 == 0 } == (1..100).select { it % 2 == 0 })
    println((1..100).filterNot { it % 2 == 0 } == (1..100).reject { it % 2 == 0 })
    println((1..10).reject { it % 2 == 0 })

    val l = 'a'..'c'
    println(l.cycle(3))

    val l2 = mutableListOf(1, 2, 3)
    val message = l2.cycle(3)
    println(message)
    l2[0] = 10
    println(message)

    val l3 = 'a'..'d'
    l3.cycle().take(10).toList().let(::println)

    val s = "abcdabcd"
    (1..s.size).find {
        s == s[0 until it].chars.cycle().take(s.size).join()
    }.let { println(it) }
}
