fun main() {
    val n = readln().toInt()
    var cnt2 = 0
    var cnt5 = 0

    for (i in 1..n) {
        if (i % 2 == 0)
            cnt2 += cntFromNum(2, i)
        if (i % 5 == 0)
            cnt5 += cntFromNum(5, i)
    }

    println(minOf(cnt2, cnt5))
}

private fun cntFromNum(target: Int, num: Int): Int {
    var cnt = 0
    var n = num

    while (n > 0 && n % target == 0) {
        cnt++
        n /= target
    }
    return cnt
}
