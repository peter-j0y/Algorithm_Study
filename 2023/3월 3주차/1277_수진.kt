import kotlin.math.pow
import kotlin.math.sqrt

fun main() {
    val (n, w) = readln().split(' ').map { it.toInt() }
    val m = readln().toFloat()

    val position = Array(n+1) { PowerPlant(0.0, 0.0) }
    val cost = DoubleArray(n+1) { Double.MAX_VALUE }

    repeat(n) { i ->
        val input = readln().split(' ').map { it.toDouble() }
        position[i+1].x = input[0]
        position[i+1].y = input[1]
    }

    cost[0] = 0.0
    val graph = Array(n+1) { DoubleArray(n+1) { -1.0 } }

    // 연결되어 있는 녀석들의 cost 는 0.
    repeat(w) {
        val (u, v) = readln().split(' ').map { it.toInt() }
        graph[u][v] = 0.0
        graph[v][u] = 0.0
    }

    // 연결 안된놈들 중 앞으로 연결할 수 있는 녀석들을 채우기
    for (i in 1..n) {
        for (j in 1..n) {
            if (graph[i][j] < 0) { // 연결 안되어있을때
                val dist = position[i].distanceFrom(position[j])
                if (dist <= m) {
                    graph[i][j] = dist
                    graph[j][i] = dist
                }
            }
        }
    }

    val queue = ArrayDeque<Int>()
    queue.addLast(1)
    cost[1] = 0.0

    while (queue.isNotEmpty()) {
        val v = queue.removeFirst()
        for (i in 1..n) {
            if (i == v) continue
            if (graph[v][i] >= 0.0 && cost[i] > cost[v] + graph[v][i]) {
                if (i !in queue)
                    queue.addLast(i)
                cost[i] = cost[v] + graph[v][i]
            }
        }
    }

    println((cost[n]*1000).toLong())
}

data class PowerPlant(
    var x: Double,
    var y: Double,
) {
    fun distanceFrom(other: PowerPlant): Double {
        return sqrt((other.x - x).pow(2) + (other.y - y).pow(2))
    }
}
