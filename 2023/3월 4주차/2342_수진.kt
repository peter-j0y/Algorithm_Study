fun main() {
    val (n, m) = readln().split(' ').map { it.toInt() }
    val lectures = readln().split(' ').map { it.toLong() }
    val sum = lectures.reduce { acc, i -> acc + i }
    val average = sum / m

    for (i in average..sum) {
        var blue = 0L
        var cnt = 0
        var idx = 0
        var fail = false
        while (idx < n) {
            if (lectures[idx] > i) {
                fail = true
                break
            }

            if (blue + lectures[idx] > i) {
                blue = 0
                cnt++
            }
            blue += lectures[idx]
            idx++
            if (cnt == m) {
                break
            }
        }

        if (fail) continue
        if (blue <= i && cnt <= m - 1) {
            println(i)
            break
        }
    }
}

