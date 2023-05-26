#include <iostream>
#include <queue>

using namespace std;

int map[502][502], visited[502][502];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

struct Node {
    int x, y, cnt;
};

int n, m, a, b, k;

bool check(int x, int y) {
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++) {
            if (map[x + i][y + j]) return false;
            if (x + i > n || y + j > m) return false;
        }
    return true;
}

int main() {
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<Node> q;

    cin >> n >> m >> a >> b >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        map[x][y] = 1;
    }

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    int ans = -1;
    q.push({sx, sy, 0});

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == ex && cur.y == ey) {
            ans = cur.cnt;
            break;
        }

        if (visited[cur.x][cur.y]) continue;
        visited[cur.x][cur.y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny]) continue;
            if (!check(nx, ny)) continue;

            q.push({nx, ny, cur.cnt + 1});
        }
    }

    cout << ans << "\n";

    return 0;
}
