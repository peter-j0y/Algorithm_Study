#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map, cnt;
int m, n;

int recursive(int x, int y) {
    if (x == m && y == n) return 1;
    if (cnt[x][y] != -1) return cnt[x][y];
    cnt[x][y] = 0;

    if (map[x + 1][y] != 0 && map[x + 1][y] < map[x][y]) {
        cnt[x][y] += recursive(x + 1, y);
    }
    if (map[x][y + 1] != 0 && map[x][y + 1] < map[x][y]) {
        cnt[x][y] += recursive(x, y + 1);
    }
    if (map[x - 1][y] != 0 && map[x - 1][y] < map[x][y]) {
        cnt[x][y] += recursive(x - 1, y);
    }
    if (map[x][y - 1] != 0 && map[x][y - 1] < map[x][y]) {
        cnt[x][y] += recursive(x, y - 1);
    }

    return cnt[x][y];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    map.resize(m + 2, vector<int>(n + 2, 0));
    cnt.resize(m + 2, vector<int>(n + 2, -1));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    cout << recursive(1, 1);

    return 0;
}
