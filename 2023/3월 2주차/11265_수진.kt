lateinit var party: Array<IntArray>


fun main() {
    val (n, m) = readln().split(' ').map { it.toInt() }

    party = Array(n + 1) { IntArray(n + 1) { Int.MAX_VALUE } }

    for (i in 1..n) {
        val input = readln().split(' ').map { it.toInt() }
        for (j in 1..n) {
            party[i][j] = input[j - 1]
        }
    }


    buildFloydWarshall(n)

    repeat(m) {
        val (a, b, c) = readln().split(' ').map { it.toInt() }
        if (party[a][b] <= c) {
            println("Enjoy other party")
        } else {
            println("Stay here")
        }
    }
}

fun buildFloydWarshall(n: Int) {
    for (k in 1..n) {
        for (i in 1..n) {
            for (j in 1..n) {
                if (party[i][j] > party[i][k] + party[k][j]) {
                    party[i][j] = minOf(party[i][j], party[i][k] + party[k][j])
                }
            }
        }
    }
}
