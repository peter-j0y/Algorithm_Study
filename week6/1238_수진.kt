val INF = 100000
fun main() {
    val (n, m, x) = readln().split(' ').map { it.toInt() }
    val graph = Array(n + 1) { Array(n + 1) { INF } }
    val reverseGraph = Array(n + 1) { Array(n + 1) { INF } }
    val dist = Array(n + 1) { INF }
    val reverseDist = Array(n + 1) { INF }

    for (i in 0 until m) {
        val (s, e, t) = readln().split(' ').map { it.toInt() }
        graph[s][e] = t
        reverseGraph[e][s] = t
    }

    partyDijkstra(graph, dist, x, n)
    partyDijkstra(reverseGraph, reverseDist, x, n)

    //prtArray(dist)
    //prtArray(reverseDist)

    var answer = 0
    for (i in 1..n) {
        answer = maxOf(answer, dist[i] + reverseDist[i])
    }
    println(answer)
}

private fun partyDijkstra(graph: Array<Array<Int>>, dist: Array<Int>, start: Int, n: Int) {
    val deque = ArrayDeque<Int>()
    val visited = Array(n + 1) { false }
    deque.addLast(start)
    dist[start] = 0

    while (deque.isNotEmpty()) {
        val v = deque.removeFirst()
        visited[v] = true


        for (i in 1..n) {
            if (graph[v][i] != INF) {
                val data = dist[v] + graph[v][i]
                if (data < dist[i]) {
                    dist[i] = data
                    deque.addLast(i)
                }
            }
        }
    }
}

private fun prtArray(array: Array<Int>) {

    array.forEach {
        if (it == INF)
            print("INF ")
        else
            print("$it ")
    }

    println("----------------")
}
