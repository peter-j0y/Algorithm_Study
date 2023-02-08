#include <iostream>

using namespace std;

#define min(a, b) a < b ? a : b

int main() {
    int n;
    int energy[21][2];
    int dp[21][2];
    int k;

    cin >> n;

    energy[0][0] = energy[0][1] = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> energy[i][0] >> energy[i][1];
    }
    cin >> k;

    dp[0][0] = 0;
    dp[0][1] = 1e9;
    dp[1][0] = energy[0][0];
    dp[1][1] = 1e9;
    dp[2][0] = min(energy[0][1], dp[1][0] + energy[1][0]);
    dp[2][1] = 1e9;

    for (int i = 3; i < n; i++) {
        dp[i][0] = min(dp[i - 2][0] + energy[i - 2][1], dp[i - 1][0] + energy[i - 1][0]);
        dp[i][1] = min(dp[i - 2][1] + energy[i - 2][1], dp[i - 1][1] + energy[i - 1][0]);
        dp[i][1] = min(dp[i - 3][0] + k, dp[i][1]);
    }

    int ans = min(dp[n - 1][0], dp[n - 1][1]);
    cout << ans;

    return 0;
}
