#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited, checked;
vector<int> v;
vector<vector<int>> map;

void func(int node) {
    if (visited[node] == 1) return;
    visited[node] = 1;

    for (auto i: map[node]) {
        if (checked[i] == 1) continue;
        if (visited[i] == 0) func(i);
        v[node] += v[i];
    }
    checked[node] = 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    visited.assign(n + 1, 0);
    v.assign(n + 1, 1);
    map.assign(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        checked.assign(n + 1, 0);
        func(i);
    }

    int max = *max_element(v.begin(), v.end());

    for (int i = 1; i <= n; i++) {
        if (v[i] == max) cout << i << ' ';
    }

    return 0;
}
