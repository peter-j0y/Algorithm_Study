class Solution {
    fun solution(n: Int): Long {
        var answer: Long = 0
        val array = Array<Long>(n+1) {0}

        if (n == 1)
            return 1L
        else if (n == 2)
            return 2L

        array[1] = 1L
        array[2] = 2L

        for (i in 3..n) {
            array[i] = (array[i-1] + array[i-2])% 1234567L
        }

        return array[n]
    }
}