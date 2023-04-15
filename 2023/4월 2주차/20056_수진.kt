val dir = mapOf(0 to Pair(-1, 0), 1 to Pair(-1, 1)
, 2 to Pair(0, 1), 3 to Pair(1, 1), 4 to Pair(1, 0),
    5 to Pair(1, -1), 6 to Pair(0, -1), 7 to Pair(-1, -1))

data class FireBall(val m: Int, val s: Int, val d: Int)

lateinit var field: HashMap<String, MutableList<FireBall>>
var n = 0
val findR = Regex("(?<=r)[\\d]+")
val findC = Regex("(?<=c)[\\d]+")

fun main() {
    val (nn, i, k) = readln().split(' ').map { it.toInt() }
    n = nn
    field = HashMap()
    var keyList = mutableListOf<String>()

    repeat(i) {
        val (r, c, m, s, d) = readln().split(' ').map { it.toInt() }
        val key = strKey(r, c)
        field[key] = mutableListOf(FireBall(m, s, d))
        keyList.add(key)
    }

    repeat(k) {
        keyList = action(keyList)
//        println("=======$it ==========")
//        keyList.forEach { key ->
//            if (field[key]!!.isNotEmpty()) {
//                println(key + ": " + field[key])
//            }
//
//        }
    }

    println(keyList.sumOf { key -> field[key]?.sumOf { it.m } ?: 0 })
}

fun action(keyList: List<String>): MutableList<String> {
    val nextField = HashMap<String, MutableList<FireBall>>()
    val mergeKeyList = mutableSetOf<String>()

    keyList.forEach { key ->
        field[key]?.forEach { fireBall ->
            val rc = keyToPair(key)
            val newRC = moveRC(rc.first, rc.second, fireBall.s, fireBall.d)
            val newKey = strKey(newRC)

            if (nextField.containsKey(newKey)) {
                nextField[newKey]!!.add(fireBall)
                mergeKeyList.add(newKey)
            } else {
                nextField[newKey] = mutableListOf(fireBall)
            }
        }
    }

    mergeKeyList.forEach { key ->
        val merged = getMergedFireBall(nextField[key]!!)
        if (merged.isEmpty()) {
            nextField.remove(key)
        } else {
            nextField[key] = merged
        }
    }

    field = nextField
    return nextField.keys.toMutableList()
}

fun strKey(r: Int, c: Int) = "r${r}c${c}"
fun strKey(p: Pair<Int, Int>) = "r${p.first}c${p.second}"

fun keyToPair(key: String): Pair<Int, Int> {
    val r = findR.find(key)?.value?.toInt() ?: 0
    val c = findC.find(key)?.value?.toInt() ?: 888
    return Pair(r, c)
}

fun moveRC(r: Int, c: Int, s: Int, d: Int): Pair<Int, Int> {
    dir[d]?.let {
        var newR = r + it.first * s
        var newC = c + it.second * s

        while (newR <= 0) {
            newR += n
        }

        while (newR > n) {
            newR -= n
        }

        while (newC <= 0) {
            newC += n
        }

        while (newC > n) {
            newC -= n
        }


        return Pair(newR, newC)
    }
    return Pair(0, 0)
}

fun getMergedFireBall(list: List<FireBall>): MutableList<FireBall> {
    if (list.isEmpty()) return mutableListOf()

    val m = list.sumOf { it.m } / 5

    if (m == 0) return mutableListOf()

    val s = list.sumOf { it.s } / list.size

    val flagD = list[0].d
    var even = true
    for (i in list.indices) {
        if (flagD % 2 != list[i].d % 2) even = false
    }

    return if (even) {
        mutableListOf(
            FireBall(m, s, 0),
            FireBall(m, s, 2),
            FireBall(m, s, 4),
            FireBall(m, s, 6)
        )
    } else {
        mutableListOf(
            FireBall(m, s, 1),
            FireBall(m, s, 3),
            FireBall(m, s, 5),
            FireBall(m, s, 7)
        )
    }

}
