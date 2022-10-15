#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct coor {
    int x;
    int y;
    int z;

    coor(int _x, int _y, int _z): x(_x), y(_y), z(_z) { };
};

int main() {
    queue<coor> q;
    int m, n, h, cnt = -999;
    int d[6][3] = {
            {1,  0,  0},
            {-1, 0,  0},
            {0,  1,  0},
            {0,  -1, 0},
            {0,  0,  1},
            {0,  0,  -1}
    };

    cin >> m >> n >> h;
    vector<vector<vector<int>>> map(n + 2, vector<vector<int>>(m + 2, vector<int>(h + 2, -1)));

    for (int k = 1; k <= h; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1)
                    q.emplace(i, j, k);
            }
        }
    }

    while (!q.empty()) {
        coor now = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            if (map[now.x + d[i][0]][now.y + d[i][1]][now.z + d[i][2]] == 0) {
                map[now.x + d[i][0]][now.y + d[i][1]][now.z + d[i][2]] = map[now.x][now.y][now.z] + 1;
                q.emplace(now.x + d[i][0], now.y + d[i][1], now.z + d[i][2]);
            }
        }
    }

    for (int k = 1; k <= h; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j][k] == 0) {
                    cnt = -1;
                    goto last;
                }
                cnt = max(cnt, map[i][j][k]);
            }
        }
    }
    last:
    if (cnt == -1)
        cout << "-1";
    else
        cout << cnt - 1;

    return 0;
}
