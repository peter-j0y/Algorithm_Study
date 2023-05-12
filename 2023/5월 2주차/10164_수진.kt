fun main() {
    val (n, m, k) = readln().split(' ').map { it.toInt() }
    val dp = Array(n) { IntArray(m) }

    if (k > 0) {
        val i = (k - 1) / m
        val j = (k - 1) % m

        for (r in (i+1) until n) {
            for (c in 0 until j) {
                dp[r][c] = -1
            }
        }

        for (r in 0 until i) {
            for (c in (j+1) until m) {
                dp[r][c] = -1
            }
        }
    }

    dp[0][0] = 1

    for (r in 0 until n) {
        for (c in 0 until m) {
            if (dp[r][c] < 0) continue

            if (r - 1 >= 0 && dp[r-1][c] > 0) dp[r][c] += dp[r - 1][c]
            if (c - 1 >= 0&& dp[r][c-1] > 0) dp[r][c] += dp[r][c - 1]
        }
    }

    println(dp[n-1][m-1])

}
