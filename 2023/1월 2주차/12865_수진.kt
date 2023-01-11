fun main() {
    val (n, k) = readln().split(' ').map { it.toInt() }
    val weights = IntArray(n + 1)
    val values = IntArray(n + 1)
    val dp = Array(n + 1) { IntArray(k + 1) }

    for (i in 1..n) {
        val (w, v) = readln().split(' ').map { it.toInt() }
        weights[i] = w
        values[i] = v
    }


    for (i in 1..n) {
        for (j in 1..k) {
            if (j-weights[i] >= 0) {
                dp[i][j] = maxOf(dp[i-1][j], dp[i-1][j-weights[i]] + values[i])
            } else {
                dp[i][j] = dp[i-1][j]
            }
        }
    }

    println(dp[n][k])
}
