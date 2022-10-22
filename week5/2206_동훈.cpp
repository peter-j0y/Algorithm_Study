#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct coor {
    coor(int i, int i1, int i2, int i3) {
        x = i;
        y = i1;
        able = i2;
        dis = i3;
    }

    int x;
    int y;
    int able;
    int dis;
};

queue<coor> q;

int main() {
    int n, m;
    int a, d;
    int x, y;
    int ans = 1e9;

    cin >> n >> m;
    cin.get();
    vector<vector<bool>> map(n + 2, vector<bool>(m + 2, false));
    vector<vector<vector<bool>>> visit(n + 2, vector<vector<bool>>(m + 2, vector<bool>(2, true)));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a = cin.get();
            if (a == '0') map[i][j] = true;
            visit[i][j][0] = visit[i][j][1] = false;
        }
        cin.get();
    }

    q.emplace(1, 1, 1, 1);
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        a = q.front().able;
        d = q.front().dis;
        q.pop();

        if (a == 1) {
            //안깼고 안깨는 방향
            if (x > 1 && map[x - 1][y] && !visit[x - 1][y][0]) {
                q.push({x - 1, y, 1, d + 1});
                visit[x - 1][y][0] = true;
            }
            if (x < n && map[x + 1][y] && !visit[x + 1][y][0]) {
                q.push({x + 1, y, 1, d + 1});
                visit[x + 1][y][0] = true;
            }
            if (y > 1 && map[x][y - 1] && !visit[x][y - 1][0]) {
                q.push({x, y - 1, 1, d + 1});
                visit[x][y - 1][0] = true;
            }
            if (y < m && map[x][y + 1] && !visit[x][y + 1][0]) {
                q.push({x, y + 1, 1, d + 1});
                visit[x][y + 1][0] = true;
            }
            //이제 깰 방향
            if (x > 1 && !map[x - 1][y] && !visit[x - 1][y][1]) {
                q.push({x - 1, y, 0, d + 1});
                visit[x - 1][y][1] = true;
            }
            if (x < n && !map[x + 1][y] && !visit[x + 1][y][1]) {
                q.push({x + 1, y, 0, d + 1});
                visit[x + 1][y][1] = true;
            }
            if (y > 1 && !map[x][y - 1] && !visit[x][y - 1][1]) {
                q.push({x, y - 1, 0, d + 1});
                visit[x][y - 1][1] = true;
            }
            if (y < m && !map[x][y + 1] && !visit[x][y + 1][1]) {
                q.push({x, y + 1, 0, d + 1});
                visit[x][y + 1][1] = true;
            }
        } else // 이미 깬 방향
        {
            if (x > 1 && map[x - 1][y] && !visit[x - 1][y][1]) {
                q.push({x - 1, y, 0, d + 1});
                visit[x - 1][y][1] = true;
            }
            if (x < n && map[x + 1][y] && !visit[x + 1][y][1]) {
                q.push({x + 1, y, 0, d + 1});
                visit[x + 1][y][1] = true;
            }
            if (y > 1 && map[x][y - 1] && !visit[x][y - 1][1]) {
                q.push({x, y - 1, 0, d + 1});
                visit[x][y - 1][1] = true;
            }
            if (y < m && map[x][y + 1] && !visit[x][y + 1][1]) {
                q.push({x, y + 1, 0, d + 1});
                visit[x][y + 1][1] = true;
            }
        }
        if (x == n && y == m) ans = min(ans, d);
    }

    if (ans == 1e9) ans = -1;
    cout << ans;

    return 0;
}