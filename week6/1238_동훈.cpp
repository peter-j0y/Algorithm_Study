#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, x;
    int s, e, t;
    int ans = -1e9;

    cin >> n >> m >> x;

    int fw[1001][1001];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) fw[i][j] = 0;
            else fw[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= n; i++)
        fw[i][i] = 0;

    for (int i = 1; i <= m; i++) {
        cin >> s >> e >> t;
        fw[s][e] = t;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (j == k) continue;

                if (fw[i][j] > fw[i][k] + fw[k][j])
                    fw[i][j] = fw[i][k] + fw[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (fw[i][x] + fw[x][i] > ans) ans = fw[i][x] + fw[x][i];

    cout << ans;

    return 0;
}