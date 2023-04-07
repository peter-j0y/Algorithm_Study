#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

int n, m;
int ans;
int d[4][2] = {{0,  1},
               {1,  0},
               {0,  -1},
               {-1, 0}};
vector<pii> cctv;
vvi map(9, vector<int>(9)), dupl(9, vector<int>(9));

void copyMap(vvi origin) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dupl[i][j] = origin[i][j];
        }
    }
}

void setLine(int sy, int sx, int idx) {
    for (int i = 1;; i++) {
        if (sy + d[idx][0] * i < 0 || sy + d[idx][0] * i >= n) break;
        else if (sx + d[idx][1] * i < 0 || sx + d[idx][1] * i >= m) break;
        else if (dupl[sy + d[idx][0] * i][sx + d[idx][1] * i] == 6) break;
        else if (dupl[sy + d[idx][0] * i][sx + d[idx][1] * i] == 0)
            dupl[sy + d[idx][0] * i][sx + d[idx][1] * i] = -1;
    }
}

void func(int idx, vvi cur) {
    if (idx == cctv.size()) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cur[i][j] == 0) tmp++;
            }
        }
        ans = ans > tmp ? tmp : ans;
        return;
    }
    pii target = cctv[idx];
    switch (map[target.first][target.second]) {
        case 1: {
            for (int i = 0; i < 4; i++) {
                copyMap(cur);
                setLine(target.first, target.second, i);
                func(idx + 1, dupl);
            }
            break;
        }
        case 2: {
            for (int i = 0; i < 2; i++) {
                copyMap(cur);
                setLine(target.first, target.second, i);
                setLine(target.first, target.second, i + 2);
                func(idx + 1, dupl);
            }
            break;
        }
        case 3: {
            for (int i = 0; i < 4; i++) {
                copyMap(cur);
                setLine(target.first, target.second, i);
                setLine(target.first, target.second, (i + 1) % 4);
                func(idx + 1, dupl);
            }
            break;
        }
        case 4: {
            for (int i = 0; i < 4; i++) {
                copyMap(cur);
                setLine(target.first, target.second, i);
                setLine(target.first, target.second, (i + 1) % 4);
                setLine(target.first, target.second, (i + 2) % 4);
                func(idx + 1, dupl);
            }
            break;
        }
        case 5: {
            copyMap(cur);
            setLine(target.first, target.second, 0);
            setLine(target.first, target.second, 1);
            setLine(target.first, target.second, 2);
            setLine(target.first, target.second, 3);
            func(idx + 1, dupl);
            break;
        }
        default:
            break;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) ans++;
            else if (map[i][j] != 6)
                cctv.emplace_back(i, j);
        }
    }

    func(0, map);
    cout << ans;

    return 0;
}
