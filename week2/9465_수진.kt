fun main() {
    val t = readLine()?.toInt() ?: return

    for (i in 0 until t) {
        println(calMax())
    }

}

fun calMax(): Int {
    val n = readLine()?.toInt() ?: return 0

    val array = Array(2) { Array(n) { 0 } }
    val list = mutableListOf<List<Int>>()

    for (i in 0..1) {
        val line = readLine()
        line?.let{ str ->
            list.add(str.split(" ").map { it.toInt() })
        }
    }

    if (n == 1)
        return maxOf(list[0][0], list[1][0])
    else if (n == 2)
        return maxOf(list[0][0] + list[1][1], list[0][1] + list[1][0])

    array[0][0] = list[0][0]
    array[1][0] = list[1][0]

    array[0][1] = array[1][0] + list[0][1]
    array[1][1] = array[0][0] + list[1][1]

    for (i in 2 until n) {
        val before2 = maxOf(array[0][i-2], array[1][i-2])

        array[0][i] = list[0][i] + maxOf(array[1][i-1], before2)
        array[1][i] = list[1][i] +maxOf(array[0][i-1], before2)
    }

    return maxOf(array[0][n-1], array[1][n-1])
}