fun main() {
    val n = readLine()!!.toInt()
    val cList = mutableListOf<Counsel>()
    val dp = Array(n + 1) { 0 }


    for (i in 1..n) {
        val (count, money) = readLine()!!.split(' ').map { it.toInt() }
        cList.add(Counsel(i, money, count))
        dayUpdate(cList)
        val pop = popCountZero(cList)
        dp[i] = dp[i - 1]

        pop.forEach {
            dp[i] = maxOf(dp[it.startDay - 1] + it.money, dp[i])
        }
    }

    println(dp[n])
}

data class Counsel(val startDay: Int, val money: Int, var count: Int)

fun dayUpdate(cList: MutableList<Counsel>) {
    cList.forEach { it.count-- }
}

fun popCountZero(cList: MutableList<Counsel>): List<Counsel> {
    val zero = cList.filter { it.count == 0 }
    zero.forEach { cList.remove(it) }
    return zero
}
