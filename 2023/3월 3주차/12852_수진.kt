data class ToOne(
    val num: Int,
    val list: MutableList<Int>,
    val cnt: Int
)


fun main() {
    val n = readln().toInt()
    val visited = BooleanArray(n + 1) { false }
    val queue = ArrayDeque<ToOne>()
    queue.addLast(ToOne(n, mutableListOf(n), 0))


    while (queue.isNotEmpty()) {
        val v = queue.removeFirst()
        visited[v.num] = true

        if (v.num == 1) {
            println(v.cnt)
            v.list.forEach {
                print("$it ")
            }
            return
        }

        if (v.num % 3 == 0 && !visited[v.num/3]) {
            val list = mutableListOf<Int>().apply {
                addAll(v.list)
                add(v.num / 3)
            }
            queue.addLast(ToOne(v.num / 3, list, v.cnt + 1))
        }

        if (v.num % 2 == 0 && !visited[v.num/2]) {
            val list = mutableListOf<Int>().apply {
                addAll(v.list)
                add(v.num / 2)
            }
            queue.addLast(ToOne(v.num / 2, list, v.cnt + 1))
        }

        if (!visited[v.num - 1]) {
            val list = mutableListOf<Int>().apply {
                addAll(v.list)
                add(v.num - 1)
            }
            queue.addLast(ToOne(v.num - 1, list, v.cnt + 1))
        }
    }

}
