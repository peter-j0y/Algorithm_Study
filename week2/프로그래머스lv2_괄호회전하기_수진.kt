import java.util.*

class Solution {
    fun isSet(peek: Char, input: Char): Boolean {
        when (peek) {
            '(' -> return input == ')'
            '{' -> return input == '}'
            '[' -> return input == ']'
        }
        return false
    }

    fun isValid(s: String, x: Int): Boolean {
        val stack = Stack<Char>()
        for (i in x until s.length) {
            if (s[i] == '(' ||s[i] == '{' ||s[i] == '[')
                stack.push(s[i])
            else {
                if (stack.size > 0 && isSet(stack.peek(), s[i]))
                    stack.pop()
                else
                    return false
            }
        }

        for (i in 0 until x) {
            if (s[i] == '(' ||s[i] == '{' ||s[i] == '[')
                stack.push(s[i])
            else {
                if (stack.size > 0 && isSet(stack.peek(), s[i]))
                    stack.pop()
                else
                    return false
            }
        }

        return stack.isEmpty()
    }

    fun solution(s: String): Int {
        var answer: Int = 0

        for (i in 0 until s.length) {
            if (isValid(s, i))
                answer++
        }

        return answer
    }
}

