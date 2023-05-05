var n = 0
var answer = 0
lateinit var graph_: IntArray
lateinit var picked: BooleanArray


fun main() {
    n = readln().toInt()
    graph_ = IntArray(n + 1)
    picked = BooleanArray(n + 1) { false }

    for (i in 1..n) {
        graph_[i] = readln().toInt()
    }

    for (i in 1..n) {
         if (!picked[i]) {
             findCycle(i)
         }
    }

    println(answer)
    for (i in 1..n) {
        if (picked[i]) {
            println(i)
        }
    }
}

fun findCycle(start: Int) {
    val visit = BooleanArray(n + 1) { false }
    val visitList = mutableListOf<Int>()
    val stack = ArrayDeque<Int>()


    stack.addLast(start)

    var last = 0
    while (stack.isNotEmpty()) {
        val v = stack.removeLast()
        visit[v] = true
        visitList.add(v)
        val next = graph_[v]
        last = next

        if (!visit[next]) stack.addLast(next)
    }

    if (last == start) {
        visitList.forEach {
            picked[it] = true
        }
        answer += visitList.size
    }
}
