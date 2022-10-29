#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    vector<vector<pair<int, int>>>dp(n + 1, vector<pair<int, int>>(m + 1, {0, 0}));
    vector<int> idx(m, 0);
    int cost;

    for (int i = 1; i <= n; i++) {
        cin >> cost;
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (cost = 0; cost <= j; cost++) {
                if(dp[cost][i - 1].first + v[j - cost][i] > dp[j][i].first) {
                    dp[j][i].first = dp[cost][i - 1].first + v[j - cost][i];
                    dp[j][i].second = j - cost;
                }
            }
        }
    }

    cout << dp[n][m].first << "\n";
    int prev = n;
    string ans = "";
    for (int i = m; i > 0; i--) {
        ans = to_string(dp[prev][i].second) + " " + ans;
        prev -= dp[prev][i].second;
    }

    cout << ans;

    return 0;
}