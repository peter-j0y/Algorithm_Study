#include <iostream>
#include <vector>

using namespace std;

#define MAX(a, b) a>b?a:b
#define MIN(a, b) a<b?a:b

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, b, tmp, ans_t = 1e9, ans_h = 0;
    int max = -1e9, min = 1e9;
    int t;

    cin >> n >> m >> b;

    vector<vector<int>> map(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            min = MIN(min, map[i][j]);
            max = MAX(max, map[i][j]);
        }
    }

    for (int k = min; k <= max; k++) {
        t = 0;
        tmp = b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] < k) {
                    t += (k - map[i][j]);
                    tmp -= (k - map[i][j]);
                } else if (map[i][j] > k) {
                    t += (map[i][j] - k) * 2;
                    tmp += (map[i][j] - k);
                }
            }
        }

        if (tmp >= 0 && ans_t >= t) {
            ans_h = k;
            ans_t = t;
        }
    }

    cout << ans_t << " " << ans_h;
    return 0;
}