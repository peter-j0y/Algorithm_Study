fun main() {
    val (n, m) = readln().split(' ').map { it.toInt() }
    val truth = readln().split(' ').map { it.toInt() }
    val people = Array(n + 1) { false }
    val party = mutableListOf<List<Int>>()
    val gura = ArrayDeque<Int>()
    var answer = Array(m + 1) { 0 }

    repeat(m) {
        val data = readln().split(' ').map { it.toInt() }
        party.add(data.subList(1, data.size))
    }

    for (i in 1..truth[0]) {
        people[truth[i]] = true
        gura.addLast(truth[i])
    }

    while (gura.isNotEmpty()) {
        val t = gura.removeFirst()

        if (!people[t]) {
            gura.addLast(t)
            people[t] = true
        }

        for (i in 0 until m) {
            if (t in party[i]) {
                answer[i] = 1
                party[i].forEach { p ->
                    if (!people[p]) {
                        people[p] = true
                        gura.addLast(p)
                    }
                }
            }
        }
    }

    println(answer.count { it == 0 } - 1)

}
