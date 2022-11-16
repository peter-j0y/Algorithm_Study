#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

int main() {
    int n, m, k;

    cin >> n >> m;

    vvi arr(n + 1, vector<int>(m + 1, 0)), sum(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }

    cin >> k;

    while (k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        int ans = sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1];
        cout << ans << "\n";
    }
}