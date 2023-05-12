fun main() {
    val t = readln().toInt()

    repeat(t) {
        val (n, k) = readln().split(' ').map { it.toInt() }
        val cost = readln().split(' ').map { it.toInt() }.toIntArray()
        val graph = Array(n + 1) { mutableListOf<Int>() }
        val dp = LongArray(n + 1) { -1L }

        repeat(k) {
            val (u, v) = readln().split(' ').map { it.toInt() }
            graph[v].add(u) // 그래프 반대로 입력
        }

        val w = readln().toInt()

        println(getCost(n, cost, graph, w, dp))
    }
}

fun getCost(n: Int, cost: IntArray, graph: Array<MutableList<Int>>, w: Int, dp: LongArray): Long {
    if (dp[w] > -1L) return dp[w]

    dp[w] = when (graph[w].size) {
        0 -> {
            cost[w - 1].toLong()
        }
        1 -> {
            cost[w - 1].toLong() + getCost(n, cost, graph, graph[w][0], dp)
        }
        else -> {
            var maxCost = 0L
            graph[w].forEach {
                maxCost = maxOf(maxCost, getCost(n, cost, graph, it, dp))
            }
            cost[w - 1].toLong() + maxCost
        }
    }

    return dp[w]
}

