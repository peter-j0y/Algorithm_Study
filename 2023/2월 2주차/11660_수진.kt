lateinit var table: Array<IntArray>
lateinit var dp: Array<IntArray>

fun main() {
    val (n, m) = readln().split(' ').map { it.toInt() }
    table = Array(n) { IntArray(n) }
    dp = Array(n) { IntArray(n) }

    for (r in 0 until n) {
        val row = readln().split(' ').map { it.toInt() }
        for (c in 0 until n) {
            table[r][c] = row[c]
        }
    }

    getDpSum(n)

    repeat(m) {
        val (sr, sc, er, ec) = readln().split(' ').map { it.toInt() - 1 }
        var answer = dp[er][ec]

        if (sc > 0) {
            answer -= dp[er][sc - 1]
        }

        if (sr > 0) {
            answer -= dp[sr - 1][ec]
        }

        if (sc > 0 && sr > 0) {
            answer += dp[sr - 1][sc - 1]
        }
        println(answer)
    }

}

fun getDpSum(n: Int) {
    dp[0][0] = table[0][0]

    // 모서리 채우기
    for (i in 1 until n) {
        dp[0][i] = dp[0][i - 1] + table[0][i]
        dp[i][0] = dp[i - 1][0] + table[i][0]
    }

    // 안 쪽 채우기
    for (r in 1 until n) {
        for (c in 1 until n) {
            dp[r][c] = dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1] + table[r][c]
        }
    }
}

