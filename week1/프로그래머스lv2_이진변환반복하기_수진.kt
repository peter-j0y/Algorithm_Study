class Solution {
    fun solution(s: String): IntArray {
        var answer: IntArray = intArrayOf(0, 0)
        var str = s
        while (str != "1") {
            val remove_zero = str.replace("0", "")
            answer[1] += str.length - remove_zero.length
            answer[0]++
            str = Integer.toBinaryString(remove_zero.length)
        }
        return answer
    }
}