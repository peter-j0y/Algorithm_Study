class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        for (h in 1..yellow) {
            if (yellow % h != 0) continue

            val w = yellow / h
            val expectBrown = 2 * h + 2 * w + 4
            if (expectBrown == brown)
                return intArrayOf(w + 2, h + 2)
        }
        return intArrayOf(0, 0)
    }
}