import kotlin.math.pow

var size = 0
var nemoCnt = 0
var n = 0
var m = 0
lateinit var nemo: Array<BooleanArray>

fun main() {
    val input = readln().split(' ').map { it.toInt() }
    n = input[0]
    m = input[1]
    size = n * m
    nemo = Array(n) { BooleanArray(m) { false } }

    nemonemo(0)

    println(2f.pow(size).toInt() - nemoCnt)
}

fun nemonemo(start: Int) {
    if (start >= size) return

    for (i in start until size) {
        nemo[i / m][i % m] = true
        if (isNemo(i)) { // 내가 넴모면 뒤에는 뭐든 다 넴모. 그만 봐~
            nemoCnt += 2f.pow(size - start - 1).toInt()
        } else {
            nemonemo(i + 1)
        }
        nemo[i / m][i % m] = false
    }
}

fun isNemo(idx: Int): Boolean { // 우측하단 기준 넴모.
    if (idx / m < 1 || idx % m < 1) return false

    val r = idx / m
    val c = idx % m
    return (nemo[r - 1][c - 1] && nemo[r - 1][c] && nemo[r][c - 1] && nemo[r][c])
}
