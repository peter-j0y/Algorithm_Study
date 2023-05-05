fun main() {
    val t = readln().toInt()
    repeat(t) {
        val n = readln().toInt()
        val coins = IntArray(1) {0} + readln().split(' ').map { it.toInt() }.toIntArray()
        val target = readln().toInt()

        println(calculateCoinDp(n, coins, target))
    }
}

fun calculateCoinDp(n: Int, coins: IntArray, target: Int): Int {
    val dp = Array(n + 1) { IntArray(target + 1) }

    for (c in 1 .. n) {
        val coin = coins[c]
        if (coin <= target) dp[c][coin] = 1 // ex) 7로 만들 수 있는 7원의 가짓수는 1개 (나야 나~)
        for (i in 0..target) {
            dp[c][i] += dp[c-1][i]
            if (i - coins[c] >= 0) {
                dp[c][i] += dp[c][i - coins[c]]
            }
        }
    }

    return dp[n][target]
}
