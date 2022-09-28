fun main() {
    val n = readLine()?.toInt()?:return
    val packArray = readLine()!!.split(" ").map{ it.toInt() }.toIntArray()
    val dp = IntArray(n + 1) { 0 }
    dp[1] = packArray[0]
    for(i in 2..n){
        setDp(i, dp, packArray)
    }
    print(dp[n])
}

fun setDp(index: Int, dpArray: IntArray, packArray: IntArray){
    dpArray[index] = packArray[index-1]
    for(i in 1..(index/2)){
        if(dpArray[index] < dpArray[i] + dpArray[index - i]){
            dpArray[index] = dpArray[i] + dpArray[index - i]
        }
    }
}