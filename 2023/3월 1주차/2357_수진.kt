lateinit var array: IntArray
lateinit var segment: Array<MM>

data class MM(var min: Int, var max: Int) {
    override fun toString() = "($min, $max)"
}

fun main() {
    val (n, m) = readln().split(' ').map { it.toInt() }
    array = IntArray(n + 1)
    segment = Array(4 * n) { MM(0, 0) } // 입력에 0 혹은 0 이하도 존재하나??

    repeat(n) {
        array[it + 1] = readln().toInt()
    }

    buildSegment(1, 1, n)

    repeat(m) {
        val (s, e) = readln().split(' ').map { it.toInt() }
        val answer = exploreSegment(1, s, e, 1, n)
        println("${answer.min} ${answer.max}")
    }
}

fun buildSegment(idx: Int, start: Int, end: Int) {
    if (start < end) {
        val center = (start + end) / 2
        buildSegment(idx * 2, start, center)
        buildSegment(idx * 2 + 1, center + 1, end)
    } else if (start == end) {
        segment[idx].min = array[start]
        segment[idx].max = array[start]
        return
    }

    segment[idx].min = minOf(segment[idx * 2].min, segment[idx * 2 + 1].min)
    segment[idx].max = maxOf(segment[idx * 2].max, segment[idx * 2 + 1].max)

}

fun exploreSegment(idx: Int, start: Int, end: Int, left: Int, right: Int): MM {
    // println("exploreSegment ($start, $end) ($left, $right)")

    return if (start == left && end == right) { // 딱코
        segment[idx]
    } else {
        val center = (left + right) / 2

        if (end <= center) { // 왼쪽 자식에 포함됨
            exploreSegment(idx * 2, start, end, left, center)
        } else if (start > center) { // 오른쪽 자식에 포함됨
            exploreSegment(idx * 2 + 1, start, end, center + 1, right)
        } else { // 걸침
            val lNode = exploreSegment(idx * 2, start, center, left, center)
            val rNode = exploreSegment(idx * 2 + 1, center + 1, end, center + 1, right)
            MM(minOf(lNode.min, rNode.min), maxOf(lNode.max, rNode.max))
        }
    }
}
