fun main() {
    var n = readLine()!!.toInt()
    val hexNumArray = calHexNum(n)
    val array = Array(n + 100) { 0 }

    array[0] = 0
    array[1] = 1
    array[2] = 2
    array[3] = 3
    array[4] = 4
    array[5] = 5
    array[6] = 1
    array[7] = 2
    array[8] = 3
    array[9] = 4
    array[10] = 5
    array[11] = 6

    if (n < 11)
        println(array[n])
    else {
        for (i in 12..n) {
            array[i] = array[i - 1] + 1

            for (hex in hexNumArray) {
                if (hex > i)
                    break
                else if (hex == i) {
                    array[i] = 1
                    break
                } else
                    array[i] = minOf(array[i], array[i - hex] + 1)

            }
        }
        println(array[n])
    }
}


fun calHexNum(until: Int): Array<Int> {
    val hexList = mutableListOf(0, 1, 6)

    var n = 3
    while (true) {
        val hexNum = n * (2 * n - 1)

        if (hexNum > until)
            return hexList.toTypedArray()
        else if (hexNum == until) {
            hexList.add(hexNum)
            return hexList.toTypedArray()
        } else {
            hexList.add(hexNum)
            n++
        }
    }
}
