import java.io.BufferedReader
import java.io.InputStreamReader


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val sb = StringBuilder()
    var bit = 0
    repeat(br.readLine().toInt()) {
        val input = br.readLine().split(' ')
        when (input[0]) {
            "add" -> bit = bit or (1 shl (input[1].toInt() - 1))
            "remove" -> bit = bit and (1 shl (input[1].toInt() - 1)).inv()
            "check" -> if (bit and (1 shl (input[1].toInt() - 1)) == 0) sb.append("0\n") else sb.append("1\n")
            "toggle" -> bit = bit xor (1 shl (input[1].toInt() - 1))
            "all" -> bit = 0.inv()
            "empty" -> bit = 0
        }
    }
    println(sb)
}
