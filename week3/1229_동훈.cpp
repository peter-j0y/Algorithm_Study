#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, target, ans = 1e9, cnt;
    vector<int> v;
    vector<int> dp(1000001, 1e9);

    cin >> n;

    for (int i = 1; 2 * i * i - i <= n; i++)
        v.push_back(2 * i * i - i);

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (auto j: v) {
            if (i == j) dp[i] = 1;
            if (i - j < 1) break;
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }

    cout << dp[n];

    return 0;
}