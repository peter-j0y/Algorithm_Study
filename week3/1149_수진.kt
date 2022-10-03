fun main() {
    val n = readLine()!!.toInt()
    val house = Array(n) {Array(3) {0} }

    val firstLine = readLine()!!.split(' ').map { it.toInt() }
    house[0][0] = firstLine[0]
    house[0][1] = firstLine[1]
    house[0][2] = firstLine[2]

    for (i in 1 until n) {
        val line = readLine()!!.split(' ').map { it.toInt() }

        house[i][0] = minOf(house[i-1][1], house[i-1][2]) + line[0]
        house[i][1] = minOf(house[i-1][0], house[i-1][2]) + line[1]
        house[i][2] = minOf(house[i-1][0], house[i-1][1]) + line[2]

    }

    house[n-1].sort()
    println(house[n-1][0])
}