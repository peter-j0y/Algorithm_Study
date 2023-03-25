import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayDeque

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val list = mutableListOf<Pair<Int, Int>>()

    var min = Int.MAX_VALUE
    var max = Int.MIN_VALUE

    repeat(n) {
        StringTokenizer(readLine()).run {
            val x = nextToken().toInt()
            val r = nextToken().toInt()

            min = minOf(min, x - r)
            max = maxOf(max, x + r)
            list.add(Pair(x - r, x + r))
        }
    }

    list.sortBy { it.first }
    val size = max - min + 1
    val array = Array<Pair<Int, Int>>(size) { Pair(0, 0) }

    for (i in list.indices) {
        val left = list[i].first - min
        val right = list[i].second - min
        if (array[left].first != 0 || array[right].first != 0) {
            println("NO")
            return
        }
        array[left] = Pair(-1, i)
        array[right] = Pair(1, i)
    }


    val stack = ArrayDeque<Pair<Int, Int>>()
    for (i in 0 until size) {
        when (array[i].first) {
            -1 -> stack.addLast(array[i])
            1 -> {
                when (stack.last().first) {
                    -1 -> {
                        if (stack.last().second == array[i].second) {
                            stack.removeLast()
                        } else {
                            stack.addLast(array[i])
                        }
                    }
                    1 -> {
                        val peek = stack.removeLast()
                        if (peek.second != array[i].second) {
                            println("NO")
                            return
                        }
                    }
                }
            }
        }
    }
    println("YES")
}
