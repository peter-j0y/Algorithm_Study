#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> list;
vector<bool> visited;

int main() {
    int n, w;
    int cnt = 0;
    queue<int> q;

    cin >> n >> w;
    list.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    q.emplace(1);

    while (!q.empty()) {
        int cur = q.front();
        bool chk = false;
        q.pop();
        visited[cur] = true;
        for (int next: list[cur]) {
            if (!visited[next]) {
                chk = true;
                q.emplace(next);
            }
        }

        if (!chk) cnt++;
    }

    cout.precision(6);
    cout << fixed << (double) w / cnt;

    return 0;
}
