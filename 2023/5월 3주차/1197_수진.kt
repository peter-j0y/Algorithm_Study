lateinit var parent: IntArray

fun main() {
    val (v, e) = readln().split(' ').map { it.toInt() }
    val edges = Array(e) { IntArray(3) }
    parent = IntArray(v + 1) { it }

    repeat(e) { i ->
        edges[i] = readln().split(' ').map { it.toInt() }.toIntArray()
    }

    edges.sortBy { it[2] }

    println(pickKruskal(v, edges))
}


fun pickKruskal(v: Int, edges: Array<IntArray>): Int {
    var edgeCnt = 0
    var weights = 0

    for (i in edges.indices) {
        val start = edges[i][0]
        val end = edges[i][1]

        if (findRoot(start) == findRoot(end)) continue

        weights += edges[i][2]
        edgeCnt++
        updateParent(start, end)

        if (edgeCnt == v - 1) return weights
    }
    return weights
}

fun findRoot(x: Int): Int {
    return if (parent[x] == x)
        x
    else {
        parent[x] = findRoot(parent[x])
        parent[x]
    }
}

fun updateParent(x: Int, y: Int) {
    val xp = findRoot(x)
    val yp = findRoot(y)

    if (xp != yp) parent[yp] = xp
}
