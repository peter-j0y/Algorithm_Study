import kotlin.math.max

val n = readln().toInt()
val board = mutableListOf<MutableList<Char>>()
var answer = 0

fun main() {
    repeat(n) {
        val row = readln().toMutableList()
        board.add(row)
    }
    answer = calculateMaxCandy()
    for (i in 0 until n) {
        for (j in 0 until n) {
            if (i + 1 < n && board[i][j] != board[i + 1][j]) {
                swapCandy(j, i, j, i + 1)
            }
            if (j + 1 < n && board[i][j] != board[i][j + 1]) {
                swapCandy(j, i, j + 1, i)
            }
        }
    }
    println(answer)
}

fun swapCandy(x: Int, y: Int, diffX: Int, diffY: Int) {
    board[y][x] = board[diffY][diffX].also { board[diffY][diffX] = board[y][x] }
    answer = max(answer, calculateMaxCandy())
    board[y][x] = board[diffY][diffX].also { board[diffY][diffX] = board[y][x] }
}

fun calculateMaxCandy(): Int {
    var maxCount = 1
    for(i in 0 until n) {
        var sameCount = 1
        for(j in 1 until n) {
            if(board[i][j-1] == board[i][j]) {
                sameCount += 1
            }
            else {
                maxCount = max(sameCount, maxCount)
                sameCount = 1
            }
        }
        maxCount = max(sameCount, maxCount)
    }

    for(j in 0 until n) {
        var sameCount = 1
        for(i in 1 until n) {
            if(board[i-1][j] == board[i][j]) {
                sameCount += 1
            }
            else {
                maxCount = max(sameCount, maxCount)
                sameCount = 1
            }
        }
        maxCount = max(sameCount, maxCount)
    }
    return maxCount
}
