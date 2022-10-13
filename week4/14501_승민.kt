val n = readln().toInt()
val t = mutableListOf(0)
val p = mutableListOf(0)
var maxTotal = 0

fun main() {
    repeat(n) {
        val (a, b) = readln().split(" ").map { it.toInt() }
        t.add(a)
        p.add(b)
    }
    consult(1, 0)
    println(maxTotal)
}

fun consult(index: Int, money: Int) {
    if(money > maxTotal) {
        maxTotal = money
    }
    if(index >= n + 1) {
        return
    }
    if(index + 1 < n + 1) {
        consult(index + 1, money)
    }
    if(index + t[index] <= n + 1) {
        consult(index + t[index], money + p[index])
    }
}
