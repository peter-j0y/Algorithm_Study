#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int map[22][22];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

struct student {
    student() {
        a = b = c = d = 0;
    }

    student(int a2, int a3, int a4, int a5) {
        a = a2, b = a3, c = a4, d = a5;
    }

    int a;
    int b;
    int c;
    int d;
};

int calc(int target, int a, int b, int c, int d) {
    if (target == a) return 1;
    if (target == b) return 1;
    if (target == c) return 1;
    if (target == d) return 1;
    else return 0;
}

int main() {
    int n;
    cin >> n;
    vector<student> v(n * n + 1, student());
    memset(map, 0, sizeof(map));

    for (int i = 0; i <= n + 1; i++)
        map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = -1;

    for (int i = 0; i < n * n; i++) {
        int num, a, b, c, d;
        cin >> num >> a >> b >> c >> d;
        v[num] = {a, b, c, d};
        int near = 0, like = 0, xx = 0, yy = 0;

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (map[x][y] != 0) continue;
                if (xx == 0) xx = x, yy = y;
                int tmpNear = 0, tmpLike = 0;
                for (int di = 0; di < 4; di++) {
                    if (map[x + dx[di]][y + dy[di]] == 0) tmpNear++;
                    tmpLike += calc(map[x + dx[di]][y + dy[di]], a, b, c, d);
                }

                if (tmpLike > like)
                    like = tmpLike, near = tmpNear, xx = x, yy = y;
                else if (tmpLike == like && tmpNear > near)
                    near = tmpNear, xx = x, yy = y;
            }
        }

        map[xx][yy] = num;
    }
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp = 0;
            int target = map[i][j];
            for (int di = 0; di < 4; di++) {
                tmp += calc(map[i + dx[di]][j + dy[di]], v[target].a, v[target].b, v[target].c, v[target].d);
            }
            switch (tmp) {
                case 1:
                    ans++;
                    break;
                case 2:
                    ans += 10;
                    break;
                case 3:
                    ans += 100;
                    break;
                case 4:
                    ans += 1000;
                    break;
                default:
                    break;
            }
        }
    }

    cout << ans;

    return 0;
}