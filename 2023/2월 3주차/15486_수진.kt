import java.util.PriorityQueue

fun main() {
    val n = readln().toInt()

    val dp = IntArray(n + 2)
    val queue = PriorityQueue<Ezhoon>()

    for (i in 1..n) {
        val (duration, value) = readln().split(' ').map { it.toInt() }
        val end = i + duration - 1
        if (end > n + 1) continue
        queue.add(Ezhoon(i, end, value))
    }

    var prevEnd = 0
    while (queue.isNotEmpty()) {
        val ez = queue.poll()

        for (i in prevEnd + 1 until ez.end) {
            dp[i] = dp[prevEnd]
        }

        val input = maxOf(dp[ez.start - 1] + ez.income, dp[ez.end - 1])
        dp[ez.end] = maxOf(input, dp[ez.end])
        prevEnd = ez.end
    }

    for (i in n downTo 0) {
        if (dp[i] > 0) {
            println(dp[i])
            return
        }
    }

    println(0)
}

data class Ezhoon(
    val start: Int,
    val end: Int,
    val income: Int
) : Comparable<Ezhoon> {
    override fun compareTo(other: Ezhoon): Int {
        return end - other.end
    }

    override fun toString(): String {
        return "$start $end $income"
    }
}

