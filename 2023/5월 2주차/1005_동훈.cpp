#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, w;
        cin >> n >> k;
        vector<vector<int>> graph(n + 1);
        vector<int> degree(n + 1), time(n + 1), order, dp(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> time[i];
        }

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b); // a -> b
            degree[b]++;
        }

        cin >> w;

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            order.push_back(now);
            for (int next : graph[now]) {
                degree[next]--;
                if (degree[next] == 0) q.push(next);
            }
        }

        for(auto i : order) {
            dp[i] = max(dp[i], time[i]);
            for(auto j : graph[i]) {
                dp[j] = max(dp[j], dp[i] + time[j]);
            }
        }

        cout << dp[w] << '\n';
    }

    return 0;
}
