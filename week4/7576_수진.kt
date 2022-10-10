fun main() {
    val (m, n) = readLine()!!.split(" ").map { it.toInt() }
    val tomato = mutableListOf<Array<Int>>()

    for (i in 0 until n) {
        tomato.add(readLine()!!.split(" ").map { it.toInt() }.toTypedArray())
    }

    if (isAllRotten(tomato))
        println("0")
    else {
        println(
            tomatoBFS(tomato, findStartTomatos(tomato, n, m), n, m)
        )
    }
}

fun prtTomato(tomato: List<Array<Int>>) {
    tomato.forEach { row ->
        row.forEach {
            print("$it ")
        }
        println()
    }
    println("_______________________")
}

fun findStartTomatos(tomato: List<Array<Int>>, n: Int, m: Int): List<Pair<Int, Int>> {
    val rotten = mutableListOf<Pair<Int, Int>>()

    for (i in 0 until n) {
        for (j in 0 until m) {
            if (tomato[i][j] == 1)
                rotten.add(Pair(i, j))
        }
    }
    return rotten
}

fun tomatoBFS(tomato: List<Array<Int>>, rotten: List<Pair<Int, Int>>, n: Int, m: Int): Int {
    var cnt = 0
    val deque = ArrayDeque<Pair<Int, Int>>()
    deque.addAll(rotten)

    val nextDeque = mutableListOf<Pair<Int, Int>>()

    while (true) {
        while (deque.isNotEmpty()) {
            val (r, c) = deque.removeFirst()

            if (r > 0 && tomato[r - 1][c] == 0) {
                tomato[r - 1][c] = 1
                nextDeque.add(Pair(r - 1, c))
            }

            if (r < n - 1 && tomato[r + 1][c] == 0) {
                tomato[r + 1][c] = 1
                nextDeque.add(Pair(r + 1, c))
            }

            if (c > 0 && tomato[r][c - 1] == 0) {
                tomato[r][c - 1] = 1
                nextDeque.add(Pair(r, c - 1))
            }

            if (c < m - 1 && tomato[r][c + 1] == 0) {
                tomato[r][c + 1] = 1
                nextDeque.add(Pair(r, c + 1))
            }
        }
        cnt++
        if (isAllRotten(tomato))
            return cnt
        else {
            if (nextDeque.isEmpty())
                return -1
            else {
                deque.addAll(nextDeque)
                nextDeque.clear()
            }

        }
    }
}

fun isAllRotten(tomato: List<Array<Int>>): Boolean {
    tomato.forEach {
        if (0 in it)
            return false
    }
    return true
}
