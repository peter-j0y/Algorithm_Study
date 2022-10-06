lateinit var brokenList: List<Int>

fun main() {
    val channel = readLine()!!.toInt()
    val brokenCnt = readLine()!!.toInt()
    brokenList = if (brokenCnt > 0)
        readLine()!!.split(" ").map { it.toInt() }
    else
        emptyList()

    val offsetFromCurrent = if (channel < 100) 100 - channel else channel - 100

    if (brokenCnt == 10) {
        println(offsetFromCurrent)
    }
    else {
        val approxiChannel = findApproxiChannel(channel)
        val offsetFroimApproxi =
            if (channel < approxiChannel)
                approxiChannel - channel + intLen(approxiChannel)
            else
                channel - approxiChannel + intLen(approxiChannel)


        println(minOf(offsetFroimApproxi, offsetFromCurrent))

    }

}

fun isValid(_num: Int): Boolean {
    if (_num == 0)
        return 0 !in brokenList
    else if (_num < 0)
        return false

    var num = _num
    while (num > 0) {
        if (num % 10 in brokenList)
            return false

        num /= 10
    }

    return true
}

fun findApproxiChannel(target: Int): Int {
    if (isValid(target))
        return target

    var i = 0
    while (true) {
        val up = target + i
        val down = target - i

        //println("$up ${isValid(up)} $down ${isValid(down)}")

        if (isValid(up) && isValid(down))
            return if (up - 100 < down - 100) up else down
        else if (isValid(up))
            return up
        else if (isValid(down))
            return down

        i++
    }
}

fun intLen(n: Int): Int {
    return n.toString().length
}