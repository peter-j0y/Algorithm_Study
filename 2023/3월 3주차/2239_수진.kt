val sudoku = Array(9) { IntArray(9) }
val area = mapOf<Int, Area>(
    0 to Area(0..2, 0..2),
    1 to Area(0..2, 3..5),
    2 to Area(0..2, 6..8),
    3 to Area(3..5, 0..2),
    4 to Area(3..5, 3..5),
    5 to Area(3..5, 6..8),
    6 to Area(6..8, 0..2),
    7 to Area(6..8, 3..5),
    8 to Area(6..8, 6..8)
)
var end = false

data class Area(val r: IntRange, val c: IntRange)


fun main() {
    for (i in 0 until 9) {
        val input = readln()
        for (j in 0 until 9) {
            sudoku[i][j] = input[j].digitToInt()
        }
    }

    backtracking(0)

    for (i in 0 until 9) {
        for (j in 0 until 9) {
            print(sudoku[i][j])
        }
        println()
    }
}


fun backtracking(idx: Int) {
    val r = idx / 9
    val c = idx % 9


    if (idx == 81) {
        end = true
        return
    }

    if (sudoku[r][c] > 0) { // 확정되어 있으면 다음칸으로
        backtracking(idx+1)
    } else {
        for (i in 1..9) {
            if (enable(r, c, i)) {
                sudoku[r][c] = i
                backtracking(idx + 1)
                if (end) {
                    return
                } else {
                    sudoku[r][c] = 0
                }
            }
        }
    }
}

fun enable(r: Int, c: Int, num: Int): Boolean {
    for (i in 0 until 9) {
        if (sudoku[r][i] == num) return false
        if (sudoku[i][c] == num) return false
    }

    indexToArea(r, c)?.let {
        for (i in it.r) {
            for (j in it.c) {
                if (sudoku[i][j] == num) return false
            }
        }
    }
   return true
}

fun indexToArea(r: Int, c: Int): Area? {
    return when (r) {
        in 0..2 -> {
            when (c) {
                in 0..2 -> area[0]
                in 3..5 -> area[1]
                in 6..8 -> area[2]
                else -> null
            }
        }

        in 3..5 -> {
            when (c) {
                in 0..2 -> area[3]
                in 3..5 -> area[4]
                in 6..8 -> area[5]
                else -> null
            }
        }

        in 6..8 -> {
            when (c) {
                in 0..2 -> area[6]
                in 3..5 -> area[7]
                in 6..8 -> area[8]
                else -> null
            }
        }

        else -> null
    }
}
