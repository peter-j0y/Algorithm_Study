fun main() {
    val n = readln().toInt()
    val triangle = Array(n+1) { IntArray(n+1) }

    for (i in 1 .. n) {
        val input = readln().split(' ').map { it.toInt() }
        for (j in input.indices) {
            val base = when (j) {
                0 -> triangle[i - 1][j]
                input.size - 1 -> triangle[i - 1][j - 1]
                else -> maxOf(triangle[i - 1][j - 1], triangle[i - 1][j])
            }
            triangle[i][j] = input[j] + base
        }
    }

    println(triangle[n].maxOrNull())
}
