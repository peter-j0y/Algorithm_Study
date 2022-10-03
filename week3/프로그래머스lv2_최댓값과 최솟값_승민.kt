class Solution {
    fun solution(s: String): String {
        var answer = ""
        val splitArray = s.split(" ").map { it.toInt() }.sorted()
        answer = splitArray.first().toString() + " " + splitArray.last().toString()
        return answer
    }
}