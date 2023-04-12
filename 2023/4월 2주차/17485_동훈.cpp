#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y, z;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> dp[3];

    for (auto &i: dp)
        i.resize(n, vector<int>(m, 1e9));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    queue<Node> q;
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < m; i++) {
            dp[k][0][i] = map[0][i];
            q.emplace(Node{0, i, k});
        }
    }

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == n - 1) continue;

        if (cur.z != 0 && cur.y != 0) {
            if (dp[0][cur.x + 1][cur.y - 1] > dp[cur.z][cur.x][cur.y] + map[cur.x + 1][cur.y - 1]) {
                dp[0][cur.x + 1][cur.y - 1] = dp[cur.z][cur.x][cur.y] + map[cur.x + 1][cur.y - 1];
                q.emplace(Node{cur.x + 1, cur.y - 1, 0});
            }
        }

        if (cur.z != 2 && cur.y != m - 1) {
            if (dp[2][cur.x + 1][cur.y + 1] > dp[cur.z][cur.x][cur.y] + map[cur.x + 1][cur.y + 1]) {
                dp[2][cur.x + 1][cur.y + 1] = dp[cur.z][cur.x][cur.y] + map[cur.x + 1][cur.y + 1];
                q.emplace(Node{cur.x + 1, cur.y + 1, 2});
            }
        }

        if (cur.z != 1) {
            if (dp[1][cur.x + 1][cur.y] > dp[cur.z][cur.x][cur.y] + map[cur.x + 1][cur.y]) {
                dp[1][cur.x + 1][cur.y] = dp[cur.z][cur.x][cur.y] + map[cur.x + 1][cur.y];
                q.emplace(Node{cur.x + 1, cur.y, 1});
            }
        }
    }
    
    int ans = 1e9;
    for (auto &k: dp) {
        for (int i = 0; i < m; i++) {
            if (k[n - 1][i] == 1e9) continue;
            ans = min(ans, k[n - 1][i]);
        }
    }
    cout << ans << "\n";

    return 0;
}
