#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited;
vector<vector<int>> map;

int recursive(int node, int cnt) {
    int ans = cnt;
    visited[node] = 1;
    ans++;

    for (auto i: map[node]) {
        if (visited[i] == 0) ans = recursive(i, ans);
    }

    return ans;
}

int main() {
    int n, m;
    int max = -1e9;
    vector<int> ans;
    cin >> n >> m;

    map.assign(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        visited.clear();
        visited.assign(n + 1, 0);
        int tmp = recursive(i, 0);
        if (tmp > max) {
            ans.clear();
            ans.push_back(i);
            max = tmp;
        } else if (tmp == max) {
            ans.push_back(i);
        }
    }

    for (auto i: ans)
        cout << i << " ";

    return 0;
}
