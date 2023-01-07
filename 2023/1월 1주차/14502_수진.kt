var n: Int = 0
var m: Int = 0
var max: Int = 0
lateinit var array: Array<Array<Int>>
val initialVirus = mutableListOf<Coordinate>()

fun main() {
    val input = readln().split(' ').map { it.toInt() }

    n = input[0]
    m = input[1]

    array = Array(n) { Array(m) { 0 } }

    for (i in 0 until n) {
        val row = readln().split(' ').map { it.toInt() }
        for (j in 0 until m) {
            array[i][j] = row[j]
            if (row[j] == 2) {
                initialVirus.add(Coordinate(j, i))
            }
        }
    }

    makeWall(0)
    println(max)
}

fun makeWall(cnt: Int) {
    if (cnt == 3) {
        simulation()
        return
    }
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (array[i][j] == 0) {
                array[i][j] = 1
                makeWall(cnt + 1)
                array[i][j] = 0
            }
        }
    }


}

fun simulation() {
    val queue = ArrayDeque<Coordinate>()
    val map = Array(n) { Array(m) { 0 } }

    for (i in 0 until n) {
        for (j in 0 until m) {
            map[i][j] = array[i][j]
        }
    }

    queue.addAll(initialVirus)

    while (queue.isNotEmpty()) {
        val v = queue.removeFirst()

        v.getSurround().forEach {
            if (map[it.y][it.x] == 0) {
                map[it.y][it.x] = 2
                queue.addLast(Coordinate(it.x, it.y))
            }
        }
    }


    var cnt = 0
    map.forEach { row ->
        cnt += row.count { it == 0 }
    }

    max = maxOf(max, cnt)
}

data class Coordinate(val x: Int, val y: Int) {
    fun getSurround(): List<Coordinate> {
        val mutableList = mutableListOf<Coordinate>()

        if (x - 1 >= 0) mutableList.add(Coordinate(x - 1, y))
        if (x + 1 < m) mutableList.add(Coordinate(x + 1, y))
        if (y - 1 >= 0) mutableList.add(Coordinate(x, y - 1))
        if (y + 1 < n) mutableList.add(Coordinate(x, y + 1))

        return mutableList
    }
}
