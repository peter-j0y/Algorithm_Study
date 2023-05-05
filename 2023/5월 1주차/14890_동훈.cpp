#include <iostream>

using namespace std;

int main() {
    int n, l;
    int map[101][101];
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int j, cnt = 0, cur = map[i][0];
        for (j = 0; j < n; j++) {
            if (cur == map[i][j]) cnt++;
            else if (cur + 1 == map[i][j]) {
                if (cnt >= l) {
                    cnt = 1;
                    cur = map[i][j];
                } else break;
            } else if (cur - 1 == map[i][j]) {
                int tmp = 0;
                for (int k = j; k < n; k++) {
                    if (map[i][k] == cur - 1)tmp++;
                    else break;
                }
                if (tmp >= l) {
                    cnt = 0;
                    cur = map[i][j];
                    j += l - 1;
                } else break;
            } else break;
        }
        if (j == n) ans++;

        cnt = 0, cur = map[0][i];
        for (j = 0; j < n; j++) {
            if (cur == map[j][i]) cnt++;
            else if (cur + 1 == map[j][i]) {
                if (cnt >= l) {
                    cnt = 1;
                    cur = map[j][i];
                } else break;
            } else if (cur - 1 == map[j][i]) {
                int tmp = 0;
                for (int k = j; k < n; k++) {
                    if (map[k][i] == cur - 1) tmp++;
                    else break;
                }
                if (tmp >= l) {
                    cnt = 0;
                    cur = map[j][i];
                    j += l - 1;
                } else break;
            } else break;
        }
        if (j == n) ans++;
    }

    cout << ans;

    return 0;
}
