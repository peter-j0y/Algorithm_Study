import kotlin.math.sqrt

fun main() {
    val n = readln().toInt()

    repeat(n) {
        val (x, y) = readln().split(' ').map { it.toInt() }
        println(alphaCentauri(y - x))
    }

}

fun alphaCentauri(dist: Int): Int {
    val n = sqrt(dist.toDouble()).toInt()
    return if (n*n == dist) {
        2*n - 1
    } else {
        2*n + (dist - n*n - 1)/n
    }
}
