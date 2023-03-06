import kotlin.math.abs

var answer = 0
lateinit var board: IntArray

fun main() {
    val n = readln().toInt()

    when (n) {
        0 -> {
            println(0)
            return
        }

        1 -> {
            println(1)
            return
        }
    }
    board = IntArray(n) { -1 }


    installQueen(0, n)
    println(answer)
}

fun installQueen(r: Int, n: Int) {
    if (r == n) {
        answer++
        return
    }

    for (c in 0 until n) {
        var available = true
        board[r] = c
        for (k in 0 until r) {
            if (board[k] < 0) continue
            if (board[r] == board[k] || abs(r - k) == abs(board[r] - board[k])) {
                available = false
                break
            }
        }
        if (available) {
            installQueen(r + 1, n)
        }
    }

}
