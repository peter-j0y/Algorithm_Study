import kotlin.math.abs

fun main() {
    val n = readln().toInt()
    val liquid = readln().split(' ').map { it.toInt() }.toIntArray()

    val answer = twoPointer(n, liquid)
    println("${liquid[answer.first]} ${liquid[answer.second]}")
}

fun twoPointer(n: Int, liquid: IntArray): Pair<Int, Int> {
    var minAbs = Int.MAX_VALUE
    var answer = Pair(0, 0)
    var l = 0
    var r = n - 1
    while (l < r) {
        val result = liquid[l] + liquid[r]

        if (abs(result) < minAbs) {
            minAbs = abs(result)
            answer = Pair(l, r)
        }

        if (result > 0) {
            r--
        } else if (result < 0) {
           l++
        } else {
            return Pair(l, r)
        }
    }

    return answer
}
