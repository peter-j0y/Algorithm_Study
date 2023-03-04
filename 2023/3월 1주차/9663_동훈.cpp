#include <iostream>

using namespace std;

int ans, n;
int map[16][16];

bool checkVert(int x, int y) {
    while (x > 0) {
        if (map[x--][y] == 1) return false;
    }
    return true;
}

bool checkDiagUp(int x, int y) {
    while (x > 0 && y > 0) {
        if (map[x--][y--] == 1) return false;
    }
    return true;
}

bool checkDiagDown(int x, int y) {
    while (x > 0 && y <= n) {
        if (map[x--][y++] == 1) return false;
    }
    return true;
}

void countQueen(int cnt, int x) {
    for (int i = 1; i <= n; i++) {
        if (checkVert(x, i) && checkDiagDown(x, i) && checkDiagUp(x, i)) {
            if (cnt == 1) {
                ans++;
                return;
            } else {
                map[x][i] = 1;
                countQueen(cnt - 1, x + 1);
                map[x][i] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    countQueen(n, 1);

    cout << ans;
    return 0;
}
