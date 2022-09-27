class Solution {
    fun solution(s: String): String {
        var answer = StringBuilder()
        var captial = true

        s.forEach{
            if (captial) {
                answer.append(it.uppercaseChar())
                captial = false
            }
            else {
                answer.append(it.lowercaseChar())
            }

            if (it == ' ')
                captial = true
        }

        return answer.toString()
    }
}