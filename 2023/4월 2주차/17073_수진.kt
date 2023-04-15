lateinit var graph: Array<MutableList<Int>>
lateinit var visited: BooleanArray

fun main() {
    val (n, w) = readln().split(' ').map { it.toInt() }

    graph = Array(n+1) { mutableListOf() }
    visited = BooleanArray(n+1) { false }

    repeat(n-1) {
        val (u, v) = readln().split(' ').map { it.toInt() }
        graph[u].add(v)
        graph[v].add(u)
    }

    println(w.toDouble()/getLeafNodeCnt(n))
}

fun getLeafNodeCnt(n: Int): Int {
    val queue = ArrayDeque<Int>()
    queue.addLast(1)
    visited[1] = true
    var leafCnt = 0

    while (queue.isNotEmpty()) {
        val v = queue.removeFirst()
        visited[v] = true
        var flag = true

        graph[v].forEach {
            if (!visited[it]) {
                queue.addLast(it)
                flag = false
            }
        }

        if (flag) leafCnt++
    }
    return leafCnt
}
