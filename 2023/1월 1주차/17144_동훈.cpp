#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int r, c, t, ans = 2, cleaner = 0;
    int map[2][60][60];

    memset(map, -1, sizeof(map));

    cin >> r >> c >> t;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            map[1][i][j] = 0;
            cin >> map[0][i][j];
            ans += map[0][i][j];
            map[1][i][j] = 0;
            if (map[0][i][j] == -1) {
                cleaner = i;
            }
        }
    }
    cleaner--;

    while (t--) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int target = map[0][i][j];
                if (map[0][i][j] != -1) {
                    if (map[0][i - 1][j] != -1) {
                        map[1][i - 1][j] += map[0][i][j] / 5;
                        target -= map[0][i][j] / 5;
                    }
                    if (map[0][i + 1][j] != -1) {
                        map[1][i + 1][j] += map[0][i][j] / 5;
                        target -= map[0][i][j] / 5;
                    }
                    if (map[0][i][j - 1] != -1) {
                        map[1][i][j - 1] += map[0][i][j] / 5;
                        target -= map[0][i][j] / 5;
                    }
                    if (map[0][i][j + 1] != -1) {
                        map[1][i][j + 1] += map[0][i][j] / 5;
                        target -= map[0][i][j] / 5;
                    }
                    map[1][i][j] += target;
                }
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                map[0][i][j] = map[1][i][j];
                map[1][i][j] = 0;
            }
        }

        for (int i = cleaner; i > 1; i--)
            map[0][i][1] = map[0][i - 1][1];
        ans -= map[0][cleaner][1];
        map[0][cleaner][1] = 0;

        for (int i = 1; i < c; i++)
            map[0][1][i] = map[0][1][i + 1];

        for (int i = 1; i < cleaner + 1; i++)
            map[0][i][c] = map[0][i + 1][c];

        for (int i = c; i > 1; i--)
            map[0][cleaner][i] = map[0][cleaner][i - 1];

        for (int i = cleaner + 1; i < r; i++)
            map[0][i][1] = map[0][i + 1][1];
        ans -= map[0][cleaner + 1][1];
        map[0][cleaner + 1][1] = 0;

        for (int i = 1; i < c; i++)
            map[0][r][i] = map[0][r][i + 1];

        for (int i = r; i > cleaner + 1; i--)
            map[0][i][c] = map[0][i - 1][c];

        for (int i = c; i > 1; i--)
            map[0][cleaner + 1][i] = map[0][cleaner + 1][i - 1];

        map[0][cleaner][1] = -1;
        map[0][cleaner + 1][1] = -1;
    }

    cout << ans;

    return 0;
}