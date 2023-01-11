fun main() {
    val input = readln().split(' ')
    val n = input[0].toInt()
    val k = input[1].toLong()
    val lans = LongArray(n)
    var max = 0L
    var min = 1L

    for (i in lans.indices) {
        lans[i] = readln().toLong()
        max = maxOf(max, lans[i])
    }

    while (min < max) {
        val center = (max + min) / 2L
        val sum = getTotalLans(lans, center)

        if (sum < k) {
            max = center
        } else {
            min = center + 1
        }
    }

    val answer = if (getTotalLans(lans, max) >= k) max else max - 1
    println(answer)
}

fun getTotalLans(lans: LongArray, divide: Long): Long {
    var sum = 0L
    lans.forEach {
        sum += it / divide
    }
    return sum
}
