#include <iostream>

using namespace std;

int n, m;
int map[26][26];

int recursive(int x, int y) {
    int ans = 0;
    if (x == n && y == m + 1) return 1;

    if (y == m + 1) y = 1, x++;

    if (map[x - 1][y - 1] != 1 || map[x - 1][y] != 1 || map[x][y - 1] != 1) map[x][y] = 1, ans += recursive(x, y + 1);
    map[x][y] = 0, ans += recursive(x, y + 1);

    return ans;
}

int main() {
    cin >> n >> m;
    cout << recursive(1, 1);

    return 0;
}