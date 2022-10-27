import java.util.PriorityQueue

val INF = 100000
val direc = listOf(Pair(-1, 0), Pair(1, 0), Pair(0, -1), Pair(0, 1))

fun main() {
    var cnt = 0
    while (true) {
        val n = readln().toInt()
        if (n == 0)
            break

        val cave = Array(n) { Array(n) {0} }

        for (i in 0 until n) {
            val row = readln().split(' ').map { it.toInt() }
            for (j in 0 until n) {
                cave[i][j] = row[j]
            }
        }

        println("Problem ${++cnt}: ${thiefRupee(cave, n)}")
    }
}

data class Rupee(val data: Int, val pos: Pair<Int, Int>) : Comparable<Rupee> {
    override fun compareTo(other: Rupee) = data - other.data
}

private fun thiefRupee(cave: Array<Array<Int>>, n: Int): Int {
    val queue = PriorityQueue<Rupee>()
    val answer = Array(n) { Array(n) { INF } }

    queue.add(Rupee(cave[0][0], Pair(0, 0)))
    answer[0][0] = cave[0][0]

    while (queue.isNotEmpty()) {
        val rupee = queue.poll()
        val (i, j) = rupee.pos

        direc.forEach {
            val x = i + it.first
            val y = j + it.second

            if (x > -1 && x < n && y > -1 && y < n) {
                val curValue = answer[i][j] + cave[x][y]
                if (answer[x][y] > curValue) {
                    answer[x][y] = curValue
                    queue.add(Rupee(cave[x][y], Pair(x, y)))
                }
            }
        }
    }

    return answer[n-1][n-1]
}

private fun prtArray(array: Array<Array<Int>>) {
    array.forEach { row ->
        row.forEach {
            if (it == INF)
                print("INF ")
            else
                print(String.format("%2d", it) + " ")
        }
        println()
    }
    println("----------------")
}
