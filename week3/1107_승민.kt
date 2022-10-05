import kotlin.math.abs
import kotlin.math.min

val n = readln().toInt()
val m = readln().toInt()
val remocon = mutableListOf(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
var answer = 0

fun main() {
    if(m > 0) {
        val removeNum = readln().split(' ').map{ it.toInt() }
        removeNum.forEach {
            remocon.remove(it)
        }
    }
    var minTemp = abs(n - 100)
    for(i in 0..1000000) {
        val tempList = i.toString().toMutableList().map{ Character.getNumericValue(it) }
        for(j in tempList.indices) {
            if(tempList[j] !in remocon) {
                break
            }
            if(j == tempList.size - 1) {
                minTemp = min(minTemp, tempList.size + abs(i - n))
            }
        }
    }
    answer = minTemp
    println(answer)
}
