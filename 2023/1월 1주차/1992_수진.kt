lateinit var array: Array<Array<Int>>

fun main() {
    val n = readln().toInt()
    array = Array(n) { Array(n) { 0 } }

    for (i in 0 until n) {
        val row = readln()
        for (j in 0 until n) {
            array[i][j] = row[j].digitToInt()
        }
    }

    quadTree(n, 0, 0, n - 1, n - 1)
}

fun quadTree(n: Int, sr: Int, sc: Int, er: Int, ec: Int) {


    val result = isAllNum(sr, sc, er, ec)
    if (result != null) {

        print(result)

    } else {
        print("(")
        quadTree(n / 2, sr, sc, er - n / 2, ec - n / 2)
        quadTree(n / 2, sr, sc + n / 2, er - n / 2, ec)
        quadTree(n / 2, sr + n / 2, sc, er, ec - n / 2)
        quadTree(n / 2, sr + n / 2, sc + n / 2, er, ec)
        print(")")
    }


}

fun isAllNum(sr: Int, sc: Int, er: Int, ec: Int): Int? {
    val first = array[sr][sc]

    for (i in sr..er) {
        for (j in sc..ec) {
            if (array[i][j] != first) {
                return null
            }
        }
    }

    return first
}
