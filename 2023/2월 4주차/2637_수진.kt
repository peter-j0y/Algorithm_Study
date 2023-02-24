lateinit var toy: Array<MutableList<Parts>>
lateinit var inDegree: IntArray

data class Parts(val num: Int, val weight: Int)

fun main() {
    val n = readln().toInt()
    val m = readln().toInt()
    val basic = mutableListOf<Int>()

    toy = Array(n + 1) { mutableListOf() }
    inDegree = IntArray(n + 1)

    repeat(m) {
        val (x, y, k) = readln().split(' ').map { it.toInt() }
        toy[x].add(Parts(y, k))
        inDegree[y]++
    }

    for (i in 1 until n) {
        if (toy[i].isEmpty()) basic.add(i) // 난 기본부품
    }

    val queue = ArrayDeque<Parts>()
    queue.add(Parts(n, 1))

    val count = IntArray(n + 1)
    count[n] = 1 // 최종 부품은 1개

    while (queue.isNotEmpty()) {
        val v = queue.removeFirst()
        toy[v.num].forEach {
            inDegree[it.num]--
            count[it.num] += count[v.num] * it.weight
            if (inDegree[it.num] == 0) {
                queue.addLast(it)
            }
        }
    }

    basic.forEach {
        println("$it ${count[it]}")
    }
}
