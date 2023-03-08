fun main() {
    val (n, k) = readln().split(' ').map { it.toInt() }

    if (n == k) {
        println(0)
    } else if (n > k) {
        println(n-k)
    } else {
        var answer = 0
        var queue = ArrayDeque<Int>()
        val visited = BooleanArray(100001) { false }
        queue.addLast(n)
        visited[n] = true
        while (true) {

            val nextQueue = ArrayDeque<Int>()
            while (queue.isNotEmpty()) {
                val v = queue.removeFirst()

                if (v == k) {
                    println(answer)
                    return
                }

                if (v > 1 && !visited[v - 1]) {
                    if (v - 1 == k) {
                        println(++answer)
                        return
                    }
                    nextQueue.addLast(v - 1)
                    visited[v - 1] = true
                }
                if (v + 1 <= 100000 && !visited[v + 1]) {
                    if (v + 1 == k) {
                        println(++answer)
                        return
                    }
                    nextQueue.addLast(v + 1)
                    visited[v + 1] = true
                }
                if (v * 2 <= 100000 && !visited[v * 2]) {
                    if (v * 2 == k) {
                        println(++answer)
                        return
                    }
                    nextQueue.addLast(v * 2)
                    visited[v * 2] = true
                }
            }
            answer++
            queue = nextQueue
        }
    }
}
