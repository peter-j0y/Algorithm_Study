#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n;
        vector<int> coin(n);

        for(int i = 0; i < n; i++) {
            cin >> coin[i];
        }
        cin >> m;

        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = coin[i]; j <= m; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[m] << "\n";
    }

    return 0;
}
