#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main() {
    int n, m, r;
    int a, b, c;
    cin >> n >> m >> r;

    vector<int> d(n + 1, 15);
    d[m] = 0;
    vector<int> item(n + 1);
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 1e9));

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
        v[i][i] = 0;
    }

    for (int i = 1; i <= r; i++) {
        cin >> a >> b >> c;
        v[a][b] = v[b][a] = c;
    }

    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (v[i][t] + v[t][j] < v[i][j])
                    v[i][j] = v[i][t] + v[t][j];
            }
        }
    }
    int tmp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (v[i][j] <= m) tmp += item[j];
        }
        if (ans < tmp)
            ans = tmp;
    }

    cout << ans;

    return 0;
}