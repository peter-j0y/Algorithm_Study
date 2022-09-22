fun main() {
    val erastos = getEratos(1000000)
    while (true) {
        val n = readLine()?.toInt()

        if (n == null || n == 0)
            break

        val b = 0

        for (b in n - 1 downTo 3) {
            if (erastos[b] && erastos[n - b]) {
                println("$n = ${n - b} + $b")
                break
            }
        }

        if (b == 3)
            println("Goldbach's conjecture is wrong.")
    }
}


fun getEratos(n: Int): List<Boolean> {
    val boolList = MutableList(n + 1) { true }

    boolList[0] = false
    boolList[1] = false

    for (i in 2..n) {
        if (boolList[i]) {
            for (j in 2..n / i) {
                boolList[i * j] = false
            }
        }
    }
    return boolList
}