var n = 0
lateinit var classroom: Array<IntArray>

fun main() {
    n = readln().toInt()
    classroom = Array(n + 1) { IntArray(n + 1) }
    val love = hashMapOf<Int, List<Int>>()

    repeat(n * n) {
        val (stu, a, b, c, d) = readln().split(' ').map { it.toInt() }
        val loveList = listOf(a, b, c, d)
        love[stu] = loveList
        val pos = findSeat(loveList)
        classroom[pos.first][pos.second] = stu
    }


    var answer = 0
    for (r in 1..n) {
        for (c in 1..n) {
            love[classroom[r][c]]?.let {
                val score = seatScore(r, c, it)
                answer += when (score) {
                    1 -> 1
                    2 -> 10
                    3 -> 100
                    4 -> 1000
                    else -> 0
                }
            }
        }
    }
    println(answer)
}

fun findSeat(love: List<Int>): Pair<Int, Int> {
    var result = Pair(0, 0)
    var maxLove = 0
    var maxEmpty = 0

    for (r in 1..n) {
        for (c in 1..n) {
            if (classroom[r][c] > 0) continue

            val lv = seatScore(r, c, love)
            if (lv > maxLove) {
                maxLove = lv
                maxEmpty = seatScore(r, c, listOf(0))
                result = Pair(r, c)
            } else if (lv == maxLove) {
                val ep = seatScore(r, c, listOf(0))
                if (ep > maxEmpty) {
                    maxEmpty = ep
                    result = Pair(r, c)
                }
            }
        }
    }

    if (result == Pair(0, 0)) {
        for (r in 1..n) {
            for (c in 1..n) {
                if (classroom[r][c] == 0)
                    return Pair(r, c)
            }
        }
    }
    return result
}

fun seatScore(r: Int, c: Int, target: List<Int>): Int {
    var score = 0
    if (r > 1 && classroom[r - 1][c] in target) score++
    if (r < n && classroom[r + 1][c] in target) score++
    if (c > 1 && classroom[r][c - 1] in target) score++
    if (c < n && classroom[r][c + 1] in target) score++
    return score
}
