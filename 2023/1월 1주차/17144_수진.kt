lateinit var room: Array<Array<Int>>
var r: Int = 0
var c: Int = 0

fun main() {
    val input = readln().split(' ').map { it.toInt() }

    r = input[0]
    c = input[1]
    val t = input[2]
    var upperCycle: Pair<Int, Int>? = null
    var underCycle: Pair<Int, Int>? = null

    room = Array(r) { Array(c) { 0 } }

    for (i in 0 until r) {
        val row = readln().split(' ').map { it.toInt() }
        for (j in 0 until c) {
            room[i][j] = row[j]
            if (room[i][j] == -1) {
                if (upperCycle == null) {
                    upperCycle = Pair(i, j)
                } else {
                    underCycle = Pair(i, j)
                }
            }
        }
    }


    repeat(t) {
        spread()
        upperCycle?.let { rotateUpper(it.first, it.second) }
        underCycle?.let { rotateUnder(it.first, it.second) }
    }


    var sum = 2
    room.forEach {
        sum += it.sum()
    }
    println(sum)
}

fun printRoom(array: Array<Array<Int>>) {
    array.forEach { row ->
        row.forEach {
            print("$it ")
        }
        println()
    }
    println("=======================")
}

fun spread() {
    val result = Array(r) { Array(c) { 0 } }

    for (i in 0 until r) {
        for (j in 0 until c) {
            if (room[i][j] > 4) {
                val surround = getSurround(i, j)

                surround.forEach {
                    result[it.first][it.second] += room[i][j]/5
                }

                result[i][j] += room[i][j] - surround.size * (room[i][j]/5)
            } else if (room[i][j] == -1) {
                result[i][j] = -1
            } else {
                result[i][j] += room[i][j]
            }

        }
    }
    room = result
}

fun rotateUpper(y: Int, x: Int) {
    for (i in y - 1 downTo 1) {
        room[i][x] = room[i-1][x]
    }

    for (j in 0 until c - 1) {
        room[0][j] = room[0][j+1]
    }

    for (i in 0 until y) {
        room[i][c - 1] = room[i + 1][c-1]
    }

    for (j in c - 1 downTo 2) {
        room[y][j] = room[y][j-1]
    }

    room[y][1] = 0
}

fun rotateUnder(y: Int, x: Int) {
    for (i in y + 1 until r - 1) {
        room[i][x] = room[i + 1][x]
    }

    for (j in 0 until c - 1) {
        room[r - 1][j] = room[r - 1][j + 1]
    }

    for (i in r - 1 downTo y) {
        room[i][c - 1] = room[i - 1][c - 1]
    }

    for (j in c - 1 downTo 2) {
        room[y][j] = room[y][j - 1]
    }

    room[y][1] = 0

}

fun getSurround(i: Int, j: Int): List<Pair<Int, Int>> {
    val list = mutableListOf<Pair<Int, Int>>()

    if (i - 1 >= 0 && room[i - 1][j] != -1) list.add(Pair(i - 1, j))
    if (i < r - 1 && room[i + 1][j] != -1) list.add(Pair(i + 1, j))
    if (j - 1 >= 0 && room[i][j - 1] != -1) list.add(Pair(i, j - 1))
    if (j < c - 1 && room[i][j + 1] != -1) list.add(Pair(i, j + 1))

    return list
}
