fun main() {
    val n = readln().toInt()
    var endFlag = false
    val arr = readln().split(' ').map { it.toInt() }.toIntArray()
    for (i in n - 1 downTo 1) {
        if (arr[i] > arr[i - 1]) {
            val changeIndex = i - 1
            val afterArr = arr.drop(changeIndex + 1)
            var minGap = 10000
            var tempIndex = 10000
            for (j in afterArr.indices) {
                if (afterArr[j] - arr[changeIndex] in 1 until minGap) {
                    minGap = afterArr[j] - arr[changeIndex]
                    tempIndex = j + changeIndex + 1
                }
            }
            arr[changeIndex] = arr[tempIndex].also { arr[tempIndex] = arr[changeIndex] }
            arr.sort(changeIndex + 1)
            println(arr.joinToString(" "))
            endFlag = true
            break
        }
    }
    if (!endFlag) {
        println(-1)
    }
}
