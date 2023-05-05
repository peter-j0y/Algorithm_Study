fun main() {
    val (n, l) = readln().split(' ').map { it.toInt() }
    val ground = Array(n) { IntArray(n) }
    var answer = 0

    repeat(n) { r ->
        ground[r] = readln().split(' ').map { it.toInt() }.toIntArray()
    }

    val dx = Array(n) { IntArray(n) } // 가로 변화량
    val dy = Array(n) { IntArray(n) } // 세로 변화량

    for (i in 0 until n) {
        for (j in 1 until n) {
            dx[i][j] = ground[i][j] - ground[i][j-1]
            dy[i][j] = ground[j][i] - ground[j-1][i]
        }
    }

    dx.forEach {
       if (isInstallable(it, l)) {
           answer++
       }
    }


    dy.forEach {
        if (isInstallable(it, l)) {
            answer++
        }
    }

    println(answer)
}

fun isInstallable(arr: IntArray, l: Int): Boolean {
    val install = BooleanArray(arr.size) { false }

    for (i in arr.indices) {
        when (arr[i]) {
            1 -> if (!upside(i, arr, l, install)) return false
            -1 ->  if (!downside(i, arr, l, install)) return false
            0 -> continue
            else -> return false
        }
    }

    return true
}

fun downside(s: Int, arr: IntArray, l: Int, install: BooleanArray): Boolean {
    if (l == 1) {
        return if (install[s])
            false
        else {
            install[s] = true
            true
        }
    }

    for (i in s + 1 until s + l) {
        if (i >= arr.size) return false
        if (arr[i] != 0) return false
        if (install[i]) return false
    }

    for (i in s + 1 until s + l) {
        install[i] = true // 경사로를 겹쳐서 설치하는 것 방지
    }
    return true
}

fun upside(s: Int, arr: IntArray, l: Int, install: BooleanArray): Boolean {
    if (l == 1) {
        return if (install[s-1])
            false
        else {
            install[s-1] = true
            true
        }
    }

    // 평평 검사
    for (i in s - l + 1 until s) {
        if (i < 0) return false
        if (arr[i] != 0) return false
    }

    // 경사로 설치 검사
    for (i in s - l until s) {
        if (i < 0) return false
        if (install[i]) return false
    }

    for (i in s - l until s) {
        install[i] = true // 경사로를 겹쳐서 설치하는 것 방지
    }

    return true
}
