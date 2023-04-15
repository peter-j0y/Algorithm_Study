fun main() {
    val (n, m) = readln().split(' ').map { it.toInt() }
    val array = Array(n) { IntArray(m) }
    val dp = Array(3) { Array(n) { IntArray(m) { Int.MAX_VALUE } } }

    repeat(n) { i ->
        val input = readln().split(' ').map { it.toInt() }
        for (j in 0 until m) {
            array[i][j] = input[j]
        }
    }

    for (j in 0 until m) {
        dp[0][0][j] = array[0][j]
        dp[1][0][j] = array[0][j]
        dp[2][0][j] = array[0][j]
    }

    for (i in 0 until n-1) {
        for (j in 0 until m) {
            for (k in 0..2) {
                if (dp[k][i][j] == Int.MAX_VALUE) continue
                when (k) {
                    0 -> {
                        dp[1][i+1][j] = minOf(dp[k][i][j] + array[i+1][j], dp[1][i+1][j])
                        if (j+1 < m) dp[2][i+1][j+1] = minOf(dp[k][i][j] + array[i+1][j+1], dp[2][i+1][j+1])
                    }
                    1 -> {
                        if (j > 0) dp[0][i+1][j-1] = minOf(dp[k][i][j] + array[i+1][j-1], dp[0][i+1][j-1])
                        if (j+1 < m) dp[2][i+1][j+1] = minOf(dp[k][i][j] + array[i+1][j+1], dp[2][i+1][j+1])
                    }
                    2 -> {
                        if (j > 0) dp[0][i+1][j-1] = minOf(dp[k][i][j] + array[i+1][j-1], dp[0][i+1][j-1])
                        dp[1][i+1][j] = minOf(dp[k][i][j] + array[i+1][j], dp[1][i+1][j])
                    }
                }
            }
        }
    }

    val mins = dp.map {
        it[n-1].minOrNull() ?: Int.MAX_VALUE
    }
    println(mins.minOrNull())
}
