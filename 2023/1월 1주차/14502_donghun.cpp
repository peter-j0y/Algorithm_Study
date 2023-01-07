#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

#define MAX(a, b) a>b?a:b

using namespace std;
int map[10][10];
int origin[10][10];

void next(int *x, int *y, int m) {
    (*y)++;
    if (*y >= m) {
        *y = 0;
        (*x)++;
    }
}

int bfs(int n, int m, int value) {
    int visit[10][10];
    memset(visit, 0, sizeof(visit));
    int i, j;
    int x, y;
    int cnt = 0;

    queue<pair<int, int>> q;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (map[i][j] == value && visit[i][j] == 0) {
                q.push({i, j});
                map[i][j] = value;
                visit[i][j] = 1;
                cnt++;
                while (!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    if (x - 1 >= 0 && map[x - 1][y] == 0 && visit[x - 1][y] == 0) {
                        q.push({x - 1, y});
                        map[x - 1][y] = value;
                        visit[x - 1][y] = 1;
                        cnt++;
                    }
                    if (x + 1 < n && map[x + 1][y] == 0 && visit[x + 1][y] == 0) {
                        q.push({x + 1, y});
                        map[x + 1][y] = value;
                        visit[x + 1][y] = 1;
                        cnt++;
                    }
                    if (y - 1 >= 0 && map[x][y - 1] == 0 && visit[x][y - 1] == 0) {
                        q.push({x, y - 1});
                        map[x][y - 1] = value;
                        visit[x][y - 1] = 1;
                        cnt++;
                    }
                    if (y + 1 < m && map[x][y + 1] == 0 && visit[x][y + 1] == 0) {
                        q.push({x, y + 1});
                        map[x][y + 1] = value;
                        visit[x][y + 1] = 1;
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}

void make_wall(int a, int b, int c, int d, int e, int f) {
    origin[a][b] = origin[c][d] = origin[e][f] = 1;
}

void break_wall(int a, int b, int c, int d, int e, int f) {
    origin[a][b] = origin[c][d] = origin[e][f] = 0;
}

int main() {
    int n, m;
    int ix, iy, jx, jy, kx, ky;
    int ans;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> origin[i][j];
        }

    ix = jx = jy = kx = ky = 0;
    ans = 0;
    iy = -1;
    while (ix < n) {
        next(&ix, &iy, m);
        if (ix >= n) break;
        if (origin[ix][iy] != 0) continue;
        else {
            jx = ix;
            jy = iy;
            while (jx < n) {
                next(&jx, &jy, m);
                if (jx >= n) break;
                if (origin[jx][jy] != 0) continue;
                else {
                    kx = jx;
                    ky = jy;
                    while (kx < n) {
                        next(&kx, &ky, m);
                        if (kx >= n) break;
                        if (origin[kx][ky] != 0) continue;
                        else {
                            make_wall(ix, iy, jx, jy, kx, ky);
                            copy(&origin[0][0], &origin[0][0] + 100, &map[0][0]);
                            bfs(n, m, 2);
                            ans = MAX(ans, bfs(n, m, 0));
                            break_wall(ix, iy, jx, jy, kx, ky);
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}