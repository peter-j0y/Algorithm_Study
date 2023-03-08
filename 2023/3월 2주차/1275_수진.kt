lateinit var array: IntArray
lateinit var segment: LongArray

fun main() {
    val (n, q) = readln().split(' ').map { it.toInt() }

    segment = LongArray(4 * n)
    array = (listOf(0) + readln().split(' ').map { it.toInt() }).toIntArray()

    buildSegmentTree(1, 1, n)

    repeat(q) {
        val (x, y, a, b) = readln().split(' ').map { it.toInt() }
        println(querySegmentTree(1, 1, n, minOf(x, y), maxOf(x, y)))
        updateSegmentTree(1, 1, n, a, b)
    }

}

fun buildSegmentTree(idx: Int, start: Int, end: Int) {
    if (start == end) {
        segment[idx] = array[start].toLong()
        return
    }

    val center = (start + end) / 2
    buildSegmentTree(idx * 2, start, center)
    buildSegmentTree(idx * 2 + 1, center + 1, end)
    segment[idx] = segment[idx * 2] + segment[idx * 2 + 1]
}

fun querySegmentTree(idx: Int, start: Int, end: Int, left: Int, right: Int): Long {
    return if (left > end || right < start) 0
    else if (left <= start && end <= right) segment[idx]
    else {
        val center = (start + end) / 2
        querySegmentTree(idx * 2, start, center, left, right) + querySegmentTree(
            idx * 2 + 1,
            center + 1,
            end,
            left,
            right
        )
    }
}

fun updateSegmentTree(idx: Int, start: Int, end: Int, target: Int, value: Int): Long {
    if (start == end && start == target) {
        segment[idx] = value.toLong()
        return segment[idx]
    }

    val center = (start + end) / 2
    if (target in start..center) {
        updateSegmentTree(idx * 2, start, center, target, value)
    } else if (target in (center + 1)..end) {
        updateSegmentTree(idx * 2 + 1, center + 1, end, target, value)
    }

    segment[idx] = segment[idx * 2] + segment[idx * 2 + 1]
    return segment[idx]
}
