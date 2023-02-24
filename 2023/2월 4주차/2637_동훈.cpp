#include <iostream>
#include <queue>

using namespace std;

struct node {
    node(int a, int b) {
        e = a;
        v = b;
    }

    int e;
    int v;
};

int n, m;
vector<vector<node>> edge;

vector<int> init() {
    vector<int> deg(n + 1, 0), visited(n + 1, 0), sorted;
    int s, e, v;

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> v;
        deg[e]++;
        edge[s].push_back(node(e, v));
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0) q.push(i);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        sorted.push_back(top);

        for (auto i: edge[top]) {
            if (visited[i.e] == 1) continue;
            deg[i.e]--;
            if (deg[i.e] == 0) q.push(i.e);
        }
    }

    return sorted;
}

int main() {
    cin >> n >> m;
    edge.assign(n + 1, vector<node>());

    vector<int> order = init();
    vector<int> count(n + 1, 0);
    count[n] = 1;

    for (auto i: order) {
        for (auto j: edge[i]) {
            count[j.e] += count[i] * j.v;
        }
    }

    for (int i = 1; i <= n; i++)
        if (edge[i].empty()) cout << i << " " << count[i] << "\n";

    return 0;
}