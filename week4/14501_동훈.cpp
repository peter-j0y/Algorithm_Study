#include <iostream>
#include <vector>
#include <utility>

#define max(a, b) a > b ? a : b

using namespace std;

int main() {
    int n;
    int ans = 1;

    cin >> n;
    vector<pair<int, int>> v(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second;

    for (int i = 1; i <= n; i++) {
        if (i + v[i].first - 1 > n) continue;
        dp[i + v[i].first - 1] = max(dp[i + v[i].first - 1], v[i].second + dp[i - 1]);
        for (int j = i + v[i].first - 1; j <= n; j++)
            dp[j] = max(dp[j], dp[i + v[i].first - 1]);
        ans = max(ans, i + v[i].first - 1);
    }

    cout << dp[ans];

    return 0;
}