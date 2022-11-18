fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val list = mutableListOf<Array<Int>>()

    repeat(n) {
        val row = readln().split(" ").map { it.toInt() }.toTypedArray()
        list.add(row)
    }

    val array = list.toTypedArray()
    val k = readln().toInt()

    repeat(k) {
        val (i, j, x, y) = readln().split(" ").map { it.toInt() - 1 }
        println(getSumInRange(i, j, x, y, array))
    }

}

private fun getSumInRange(i: Int, j: Int, x: Int, y: Int, array: Array<Array<Int>>): Int {
    var sum = 0

    for (p in i..x) {
        for (k in j..y) {
            sum += array[p][k]
        }
    }

    return sum
}
