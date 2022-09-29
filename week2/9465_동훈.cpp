#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int[2]> dp(n + 1), score(n + 1);
        for (int k = 0; k < 2; k++) {
            for (int i = 1; i <= n; i++)
                cin >> score[i][k];
        }
        dp[1][0] = score[1][0]; dp[1][1] = score[1][1];

        for (int i = 2; i <= n; i++) {
            dp[i][0] = score[i][0];
            dp[i][0] += max(dp[i - 1][1], dp[i - 2][1]);
            dp[i][1] = score[i][1];
            dp[i][1] += max(dp[i - 1][0], dp[i - 2][0]);
        }
        int ans = max(dp[n][0], dp[n][1]);
        cout << ans << "\n";
    }
    return 0;
}