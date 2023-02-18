import java.math.BigInteger

fun main() {
    val (n, m) = readln().split(' ').map { it.toInt() }
    // oI7ㅓ| 되Lㅔ
    println(getFactorial(n).divide(getFactorial(n - m).multiply(getFactorial(m))))

}

fun getFactorial(n: Int): BigInteger {
    return if (n == 0) BigInteger.ONE else getFactorial(n - 1).multiply(n.toBigInteger())
}
