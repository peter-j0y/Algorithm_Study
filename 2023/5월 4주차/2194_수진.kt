lateinit var field: Array<IntArray>
var a = 0
var b = 0

fun main() {
    val (n, m, a_, b_, k) = readln().split(' ').map { it.toInt() }
    field = Array(n) { IntArray(m) { Int.MAX_VALUE } }
    a = a_
    b = b_

    repeat(k) {
        val (r, c) = readln().split(' ').map { it.toInt() - 1 }
        field[r][c] = -1 // 장애물은 -1
    }

    val start = readln().split(' ').map { it.toInt() - 1 }
    val end = readln().split(' ').map { it.toInt() - 1 }
    val dir = listOf(Pair(-1, 0), Pair(1, 0), Pair(0, -1), Pair(0, 1))
    val queue = ArrayDeque<Pair<Int, Int>>()
    queue.addLast(Pair(start[0], start[1]))
    field[start[0]][start[1]] = 0

    while (queue.isNotEmpty()) {
        val v = queue.removeFirst()

        repeat(4) {
            val row = v.first + dir[it].first
            val col = v.second + dir[it].second
            if (canMove(row, col)) {
                if (field[row][col] > field[v.first][v.second] + 1) { // 최솟값으로 갱신될때만 큐에 넣기
                    queue.addLast(Pair(row, col)) // 2번 그 이상의 방문에서 더 작을 수 있으니.. 방문 처리를 이렇게 해야할듯?
                    field[row][col] = field[v.first][v.second] + 1
                }
            }
        }
    }

    if (field[end[0]][end[1]] == Int.MAX_VALUE) {
        println(-1)
    } else {
        println(field[end[0]][end[1]])
    }


}

fun canMove(r: Int, c: Int): Boolean {
    for (i in 0 until a) {
        if (r + i < 0 || r + i >= field.size) return false
        for (j in 0 until b) {
            if (c + j < 0 || c + j >= field[r + i].size) return false
            if (field[r + i][c + j] == -1) return false
        }
    }
    return true
}
