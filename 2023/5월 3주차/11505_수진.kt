lateinit var data: LongArray
lateinit var segTree: LongArray

fun main() {
    val (n, m, k) = readln().split(' ').map { it.toInt() }
    data = LongArray(n)
    segTree = LongArray(4 * n)

    repeat(n) {
        data[it] = readln().toLong()
    }

    init(0, n - 1, 1)

    repeat(m+k) {
        val (a, b, c) = readln().split(' ').map { it.toInt() }
        when (a) {
            1 -> {
                update(0, n-1, 1, b - 1, c.toLong())
            }
            2 -> {
                println(query(0, n - 1, b-1, c-1, 1))
            }
        }
    }
}

fun init(start: Int, end: Int, node: Int): Long {
    if (start == end) {
        segTree[node] = data[start] % 1000000007
        return segTree[node]
    }

    val mid = (start + end) / 2
    segTree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1) % 1000000007
    return segTree[node]
}

fun query(start: Int, end: Int, left: Int, right: Int, node: Int): Long {
    if (right < start || left > end) return 1 // 범위 벗어남

    if (left <= start && end <= right) return segTree[node] // 범위 안에 폭 들어감

    val mid = (start + end) / 2

    return query(start, mid, left, right, node * 2) * query(mid + 1, end, left, right, node * 2 + 1) % 1000000007
}

fun update(start: Int, end: Int, node: Int, target: Int, value: Long) {
    if (start == end) {
        segTree[node] = value
        return
    }

    val mid = (start + end) / 2

    if (target in start..mid) {
        update(start, mid, node * 2, target, value)
    } else {
        update(mid + 1, end, node * 2 + 1, target, value)
    }
    segTree[node] = segTree[node * 2] * segTree[node * 2 + 1] % 1000000007
}
