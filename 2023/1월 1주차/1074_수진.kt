import kotlin.math.pow

fun main() {
    val (n, r, c) = readln().split(" ").map { it.toInt() }
    val k = 2f.pow(n).toInt()

    println(recursion(k, r, c, 0, 0, 0))
}

fun recursion(k: Int, r: Int, c: Int, originValue: Int, originX: Int, originY: Int): Int {
    if (k == 1) {
        return originValue
    } else {
        val unitValue = k / 2 * k / 2

        val rangeX = c in originX until originX + k / 2
        val rangeY = r in originY until originY + k / 2

        return if (rangeY) {
            if (rangeX) {
                recursion(k / 2, r, c, originValue, originX, originY)
            } else {
                recursion(k / 2, r, c, originValue + unitValue, originX + k / 2, originY)
            }
        } else {
            if (rangeX) {
                recursion(k / 2, r, c, originValue + unitValue * 2, originX, originY + k / 2)
            } else {
                recursion(k / 2, r, c, originValue + unitValue * 3, originX + k / 2, originY + k / 2)
            }
        }


    }
}
