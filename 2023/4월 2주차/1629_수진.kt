fun main() {
    val (a, b, c) = readln().split(' ').map { it.toLong() }
    println(pow(a, b, c))
}

fun pow(a: Long, b: Long, c: Long): Long {
    if (b == 1L) return a % c

    val half = pow(a, b/2, c)
    return if (b % 2 == 0L) {
        (half * half) % c
    } else {
        ((half * half) % c * a) % c
    }
}
