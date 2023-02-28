lateinit var parent: IntArray
lateinit var noRootTree: Array<MutableList<Int>>


fun main() {
    val n = readln().toInt()

    parent = IntArray(n + 1)
    noRootTree = Array(n + 1) { mutableListOf() }

    repeat(n-1) {
        val (u, v) = readln().split(' ').map { it.toInt() }
        noRootTree[u].add(v)
        noRootTree[v].add(u)
    }

    findParent(n)

    for (i in 2..n) {
        println(parent[i])
    }
}

fun findParent(n: Int) {
    val queue = ArrayDeque<Int>()
    queue.addLast(1)

    while (queue.isNotEmpty()) {
        val v = queue.removeFirst()
        noRootTree[v].forEach { u ->
            if (parent[u] == 0) {
                parent[u] = v
                queue.addLast(u)
            }
        }
    }
}
