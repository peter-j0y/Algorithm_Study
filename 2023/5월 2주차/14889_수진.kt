import kotlin.math.abs

lateinit var synergy: Array<IntArray>
var diff = Int.MAX_VALUE

fun main() {
    val n = readln().toInt()
    synergy = Array(n) { IntArray(n) }

    repeat(n) { i ->
        synergy[i] = readln().split(' ').map { it.toInt() }.toIntArray()
    }

    pickMember(0, mutableListOf(0), n)
    println(diff)
}

fun pickMember(i: Int, members: MutableList<Int>, n: Int) {
    if (members.size == n/2) {
        calculatePowerDiff(members, n)
        return
    }

    for (k in (i+1) until n) {
        val list = mutableListOf(k)
        list.addAll(members)
        pickMember(k, list, n)
    }
}

fun calculatePowerDiff(teamA: List<Int>, n: Int) {
    val teamB = mutableListOf<Int>()
    teamB.addAll(0 until n)
    teamB.removeAll(teamA)

    var teamASum = 0
    var teamBSum = 0
    for (i in 0 until teamA.size - 1) {
        for (j in (i + 1) until teamA.size) {
            teamASum += synergyBetween(teamA[i], teamA[j])
            teamBSum += synergyBetween(teamB[i], teamB[j])
        }
    }

    diff = minOf(diff, abs(teamASum - teamBSum))
}

fun synergyBetween(a: Int, b: Int): Int {
    return synergy[a][b] + synergy[b][a]
}
