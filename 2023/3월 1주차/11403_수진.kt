lateinit var graph: Array<IntArray>
lateinit var result: Array<IntArray>

fun main() {
    val n = readln().toInt()

    graph = Array(n) { IntArray(n) }
    result = Array(n) { IntArray(n) }

    for (i in 0 until n) {
        val input = readln().split(' ')
        for (j in 0 until n) {
             if (input[j] == "1") graph[i][j] = 1
        }
    }

    for (i in 0 until n) {
        letsGo(i, n)
    }

    result.forEach { row ->
        row.forEach {
            print("$it ")
        }
        println()
    }
}

fun letsGo(start: Int, n: Int) {
    val queue = ArrayDeque<Int>()

    for (i in 0 until n) {
        if (graph[start][i] == 1) {
            queue.addLast(i)
            result[start][i] = 1
        }
    }

     while (queue.isNotEmpty()) {
         val v = queue.removeFirst()
         for (i in 0 until n) {
             if (result[start][i] == 0 && graph[v][i] == 1) {
                 queue.addLast(i)
                 result[start][i] = 1
             }
         }
     }

}
