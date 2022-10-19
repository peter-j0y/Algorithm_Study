import kotlin.math.abs

val n = readln().toInt()
var answer = 0

val arr = readln().split(' ').map{ it.toInt() }.toMutableList()

fun main() {
    permutation(arr, 0, n-1)
    print(answer)
}

fun cal(arr: List<Int>) {
    var temp = 0
    for(idx in 0 until arr.size - 1) {
        temp += abs(arr[idx] - arr[idx + 1])
    }
    if (answer < temp) {
        answer = temp
    }
}

fun permutation(arr: MutableList<Int>, start: Int, end: Int) {
    if(start >= end) {
        cal(arr)
        return
    }
    for(idx in start..end) {
        arr[start] = arr[idx].also{ arr[idx] = arr[start] }
        permutation(arr, start + 1, end)
        arr[start] = arr[idx].also{ arr[idx] = arr[start] }
    }
}
