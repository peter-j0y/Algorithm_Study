#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
vector<bool> visited;

int far = 0;
int dmt = 0;

vector<vector<pair<int, int>>> tree;

void recursive(int node, int cost) {
    if (visited[node]) return;

    visited[node] = true;

    if (dmt < cost) {
        dmt = cost;
        far = node;
    }

    for (int i = 0; i < tree[node].size(); i++)
        recursive(tree[node][i].first, cost + tree[node][i].second);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int v;
    int s, e, d;

    cin >> v;
    tree.assign(v + 1, vector<pair<int, int>>());

    for (int i = 0; i < v; i++) {
        cin >> s;

        while (true) {
            cin >> e;
            if (e == -1) break;

            cin >> d;
            tree[s].emplace_back(e, d);
        }
    }

    visited.assign(v + 1, false);
    recursive(1, 0);

    visited.assign(v + 1, false);
    recursive(far, 0);

    cout << dmt;

    return 0;
}