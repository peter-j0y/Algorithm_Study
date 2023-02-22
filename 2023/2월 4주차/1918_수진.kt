fun main() {
    val input = readln()
    val bracket = insertBracket(input)
    println(makePostfix(bracket))
}

fun insertBracket(input: String): String {
    val list = mutableListOf<String>()

    val stringBuilder = StringBuilder()
    var bracketOpen = 0
    var bracketClose = 0
    for (c in input) {

        when (c) {
            '(' -> {
                if (bracketOpen > 0)
                    stringBuilder.append(c)
                bracketOpen++
            }
            ')' -> {
                bracketClose++
                if (bracketOpen == bracketClose) {
                    val child = stringBuilder.toString()
                    list.add(insertBracket(child))
                    stringBuilder.clear()
                    bracketOpen = 0
                    bracketClose = 0
                } else {
                    stringBuilder.append(")")
                }
            }
            else -> {
                if (bracketOpen > 0)
                    stringBuilder.append(c)
                else
                    list.add(c.toString())
            }
        }

    }

    val mulDiv = bindByOperator(list, listOf("*", "/"))
    val plusMinus = bindByOperator(mulDiv, listOf("+", "-"))
    return plusMinus[0]
}

fun bindByOperator(list: List<String>, operator: List<String>): List<String> {
    val deque = ArrayDeque<String>()
    val sb = StringBuilder()
    var making = false

    for (s in list) {
        if (making) {
            sb.append(s)
            sb.append(")")
            deque.addLast(sb.toString())
            sb.clear()
            making = false
        } else {
            if (s in operator) {
                sb.append("(")
                sb.append(deque.removeLast())
                sb.append(s)
                making = true
            } else {
                deque.addLast(s)
            }
        }
    }

    return deque.toList()
}

fun makePostfix(prefix: String): String {
    val stack = ArrayDeque<String>()

    for (c in prefix) {
        if (c == ')') {
            val b = stack.removeLast()
            val op = stack.removeLast()
            val a = stack.removeLast()
            stack.removeLast()
            stack.addLast("$a$b$op")
        } else {
            stack.addLast(c.toString())
        }
    }
    return stack.removeLast()
}
