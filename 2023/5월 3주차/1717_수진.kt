lateinit var union: IntArray

fun main() {
    val (n, m) = readln().split(' ').map { it.toInt() }
    union = IntArray(n + 1) { it }

    repeat(m) {
        val (op, a, b) = readln().split(' ').map { it.toInt() }
        when (op) {
            0 -> {
                updateUnion(a, b)
            }
            1 -> {
                if (findRoot(a) == findRoot(b)) {
                    println("YES")
                } else {
                    println("NO")
                }
            }
        }
    }
}

fun findRoot(x: Int): Int {
    return if (union[x] == x) // 나 하나만 포함
        x
    else {
        union[x] = findRoot(union[x]) // Root 찾기
        union[x]
    }
}

fun updateUnion(x: Int, y: Int) {
    val xr = findRoot(x)
    val yr = findRoot(y)

    if (xr != yr) union[yr] = xr
}
