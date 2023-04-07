#include <iostream>

#define MAX 1e9

using namespace std;

int N;
int cost[16][16];
int dp[16][1 << 16];

int tsp(int cur, int visited) {
    // 이미 다녀온 곳들만 다녀온 경우 -> 계산 똑같으니까 다시 할 필요 없음
    if (dp[cur][visited] != 0)
        return dp[cur][visited];

    // 모든 곳을 다 다녀온 경우
    if (visited == (1 << N) - 1) {
        // 갈 수 있는 곳이라면
        if (cost[cur][0] != 0)
            return cost[cur][0];
        // 자기 자신일 때
        else
            return MAX;
    }

    int result = MAX;
    for (int i = 0; i < N; i++) {
        // 자기 자신이 아니고 아직 안 간 곳이라면
        if (!((1 << i) & visited) && (cost[cur][i] != 0)) {
            // 지금까지 계산한 값과 지금 갈 곳 중 최솟값을 저장
            result = min(result, cost[cur][i] + tsp(i, visited + (1 << i)));
        }
    }
    // 계산한 최솟값 dp에 저장
    dp[cur][visited] = result;
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    cout << tsp(0, 1) << "\n";
    return 0;
}
