fun main() {
    val n = readLine()!!.toInt()
    val house = mutableListOf<Array<Int>>()
    for (i in 0 until n) {
        house.add(readLine()!!.map { Character.getNumericValue(it) }.toTypedArray())
    }

    val answer = getHouseNumList(house, n)
    println(answer.size)
    answer.sorted().forEach{ println(it) }
}

fun getHouseNumList(house: List<Array<Int>>, n: Int): List<Int> {
    val numList = mutableListOf<Int>()
    val stack = ArrayDeque<Pair<Int, Int>>()

    while (true) {
        var cnt = 0
        val startIdx = findUntrackedHouse(house, n) ?: return numList
        stack.addLast(startIdx)
        while (stack.isNotEmpty()) {
            val idx = stack.removeLast()
            val r = idx.first
            val c = idx.second
            if (house[r][c] == 1) {
                house[r][c] = 0
                cnt++

                if (r > 0 && house[r - 1][c] == 1)
                    stack.addLast(Pair(r - 1, c))

                if (r < n - 1 && house[r + 1][c] == 1)
                    stack.addLast(Pair(r + 1, c))

                if (c > 0 && house[r][c - 1] == 1)
                    stack.addLast(Pair(r, c - 1))

                if (c < n - 1 && house[r][c + 1] == 1)
                    stack.addLast(Pair(r, c + 1))
            }
        }
        numList.add(cnt)
    }
}

fun findUntrackedHouse(house: List<Array<Int>>, n: Int): Pair<Int, Int>? {
    for (i in 0 until n) {
        for (j in 0 until n) {
            if (house[i][j] == 1)
                return Pair(i, j)
        }
    }
    return null
}

fun prtHouse(house: List<Array<Int>>, n: Int) {
    for (i in 0 until n) {
        for (j in 0 until n) {
            print(house[i][j])
        }
        println()
    }
    println("__________________")
}
