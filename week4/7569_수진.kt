fun main() {
    val (m, n, h) = readLine()!!.split(" ").map { it.toInt() }
    val tomatoBox = mutableListOf<MutableList<Array<Int>>>()

    for (j in 0 until h) {
        val tomato = mutableListOf<Array<Int>>()
        for (i in 0 until n) {
            tomato.add(readLine()!!.split(" ").map { it.toInt() }.toTypedArray())
        }
        tomatoBox.add(tomato)
    }
    //prtTomatoBox(tomatoBox)

    if (isAllRottenBox(tomatoBox))
        println("0")
    else {
        println(
            tomatoBoxBFS(tomatoBox, findStartTomatoes(tomatoBox, n, m, h), n, m, h)
        )
    }
}

fun prtTomatoBox(tomato: List<List<Array<Int>>>) {
    tomato.forEach { box ->
        box.forEach { row ->
            row.forEach { print("$it ") }
            println()
        }
        println()
    }
    println("_______________________")
}

fun findStartTomatoes(tomato: List<List<Array<Int>>>, n: Int, m: Int, h: Int): List<Triple<Int, Int, Int>> {
    val rotten = mutableListOf<Triple<Int, Int, Int>>()

    for (k in 0 until h) {
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (tomato[k][i][j] == 1)
                    rotten.add(Triple(k, i, j))
            }
        }
    }

    return rotten
}

fun tomatoBoxBFS(tomato: List<List<Array<Int>>>, rotten: List<Triple<Int, Int, Int>>, n: Int, m: Int, h: Int): Int {
    var cnt = 0
    val deque = ArrayDeque<Triple<Int, Int, Int>>()
    deque.addAll(rotten)

    val nextDeque = mutableListOf<Triple<Int, Int, Int>>()

    while (true) {
        while (deque.isNotEmpty()) {
            val (b, r, c) = deque.removeFirst()

            if (r > 0 && tomato[b][r - 1][c] == 0) {
                tomato[b][r - 1][c] = 1
                nextDeque.add(Triple(b, r - 1, c))
            }

            if (r < n - 1 && tomato[b][r + 1][c] == 0) {
                tomato[b][r + 1][c] = 1
                nextDeque.add(Triple(b, r + 1, c))
            }

            if (c > 0 && tomato[b][r][c - 1] == 0) {
                tomato[b][r][c - 1] = 1
                nextDeque.add(Triple(b, r, c - 1))
            }

            if (c < m - 1 && tomato[b][r][c + 1] == 0) {
                tomato[b][r][c + 1] = 1
                nextDeque.add(Triple(b, r, c + 1))
            }

            if (b > 0 && tomato[b - 1][r][c] == 0) {
                tomato[b - 1][r][c] = 1
                nextDeque.add(Triple(b - 1, r, c))
            }

            if (b < h - 1 && tomato[b + 1][r][c] == 0) {
                tomato[b + 1][r][c] = 1
                nextDeque.add(Triple(b + 1, r, c))
            }
        }

        cnt++
        if (isAllRottenBox(tomato))
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

fun isAllRottenBox(tomato: List<List<Array<Int>>>): Boolean {
    tomato.forEach { box ->
        box.forEach { row ->
            if (0 in row)
                return false
        }
    }
    return true
}
