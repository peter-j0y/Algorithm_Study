val rootEarlySet = mutableSetOf<Int>()
val rootNotEarlySet = mutableSetOf<Int>()
lateinit var tree: Array<IntArray>
lateinit var visitedE: BooleanArray
lateinit var visitedNE: BooleanArray
var n = 0

fun main() {
    n = readln().toInt()
    tree = Array(n + 1) { IntArray(n + 1) }

    repeat(n - 1) {
        val (u, v) = readln().split(' ').map { it.toInt() }

        tree[u][v] = 1
        tree[v][u] = 1
    }

    visitedE = BooleanArray(n + 1) { false }
    visitedNE = BooleanArray(n + 1) { false }

    dfsRootEarly(1, true)
    dfsRootNotEarly(1, false)

    println(minOf(rootEarlySet.size, rootNotEarlySet.size))
}

fun dfsRootEarly(cur: Int, early: Boolean) {
    visitedE[cur] = true

    for (i in 1..n) {
        if (tree[cur][i] == 1 && visitedE[i].not()) {
            if (early.not()) {
                rootEarlySet.add(i)
                dfsRootEarly(i, true)
            } else {
                dfsRootEarly(i, false)
            }
        }
    }

}


fun dfsRootNotEarly(cur: Int, early: Boolean) {
    visitedNE[cur] = true
    for (i in 1..n) {
        if (tree[cur][i] == 1 && visitedNE[i].not()) {
            if (early.not()) {
                rootNotEarlySet.add(i)
                dfsRootEarly(i, true)
            } else {
                dfsRootEarly(i, false)
            }
        }
    }
}
