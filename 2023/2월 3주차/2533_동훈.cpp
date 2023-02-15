#include <iostream>
#include <vector>

using namespace std;

#define N 1000001

vector<int> edge[N];
int visited[N], dp[N][2];

void dfs(int n) {
    visited[n] = 1;
    dp[n][0] = 1;

    for(auto i : edge[n]) {
        if (visited[i] == 1) continue;
        dfs(i);

        dp[n][1] += dp[i][0];
        dp[n][0] += (dp[i][1] < dp[i][0] ? dp[i][1] : dp[i][0]);
    }
}

int main() {
    int n;
    int u, v;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1);

    cout << (dp[1][1] < dp[1][0] ? dp[1][1] : dp[1][0]);

    return 0;
}