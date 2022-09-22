#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main() {
    int n, m;
    int s, e, c;

    cin >> n >> m;
    vector<vector<pair<int, int>>> linked(n + 1, vector<pair<int, int>>());
    vector<int> visit(n + 1, 0);
    vector<int> d(n + 1, 1e9);
    vector<int> ans;

    while (m--) {
        cin >> s >> e >> c;
        linked[s].push_back(make_pair(c, e));
    }
    cin >> s >> e;
    d[s] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int dis = -pq.top().first;
        pq.pop();

        if (cur == e) break;
        if (d[cur] < dis) continue;
        for (auto i: linked[cur]) {
            int next = i.second;
            int nextdis = dis + i.first;

            if (nextdis < d[next]) {
                d[next] = nextdis;
                pq.push(make_pair(-nextdis, next));
                visit[next] = cur;
            }
        }
    }

    int t = e;
    while (t) {
        ans.push_back(t);
        t = visit[t];
    }

    cout << d[e] << "\n";
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    return 0;
}