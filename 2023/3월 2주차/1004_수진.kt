import kotlin.math.pow
import kotlin.math.sqrt

fun main() {
    val t = readln().toInt()

    repeat(t) {
        val (x1, y1, x2, y2) = readln().split(' ').map { it.toFloat() }
        val n = readln().toInt()
        var answer = 0
        repeat(n) {
            val (cx, cy, r) = readln().split(' ').map { it.toFloat() }
            if ((isInsideCircle(x1, y1, cx, cy, r) && isInsideCircle(x2, y2, cx, cy, r).not())
                || (isInsideCircle(x1, y1, cx, cy, r).not() && isInsideCircle(x2, y2, cx, cy, r))
            ) {
                answer++
            }
        }
        println(answer)
    }
}

fun isInsideCircle(x: Float, y: Float, cx: Float, cy: Float, r: Float): Boolean {
    val dist = sqrt((x - cx).pow(2) + (y - cy).pow(2))
    return dist <= r
}
