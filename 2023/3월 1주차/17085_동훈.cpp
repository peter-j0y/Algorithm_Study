#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m, K;

    cin >> n >> m;

    K = (n - 1) / 2;

    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<pii>> list(K + 1, vector<pii>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.') continue;

            int k;
            list[0].emplace_back(i, j);
            for (k = 1; k <= K; k++) {
                if (i - k < 0 || map[i - k][j] == '.') break;
                if (i + k >= n || map[i + k][j] == '.') break;
                if (j - k < 0 || map[i][j - k] == '.') break;
                if (j + k >= m || map[i][j + k] == '.') break;
                list[k].emplace_back(i, j);
            }
        }
    }

    for (int i = K; i >= 0; i--) {
        for (int j = K; j >= i; j--) {
            int ans = (i * 4 + 1) * (j * 4 + 1);
            if (ans == 1) {
                cout << ans;
                return 0;
            }
            for (auto first: list[j]) {
                for (auto second: list[i]) {
                    // y축이 애초에 먼 경우
                    if (abs(first.first - second.first) > i + j) {
                        cout << ans;
                        return 0;
                    }
                        // x축이 애초에 먼 경우
                    else if (abs(first.second - second.second) > i + j) {
                        cout << ans;
                        return 0;
                    }
                        // 안쪽 범위인데 좌표 중에 하나가 같은 경우
                    else if (first.first == second.first || first.second == second.second) continue;

                        // first 기준으로 second가 1사분면
                    else if (first.first > second.first && first.second < second.second) {
                        if (second.first + i >= first.first && second.second <= first.second + j) continue;
                        else if (second.second - i <= first.second && second.first >= first.first - j) continue;
                        cout << ans;
                        return 0;
                    }
                        // first 기준으로 second가 2사분면
                    else if (first.first < second.first && first.second < second.second) {
                        if (second.first - i <= first.first && second.second <= first.second + j) continue;
                        else if (second.second - i <= first.second && second.first <= first.first + j) continue;
                        cout << ans;
                        return 0;
                    }
                        // first 기준으로 second가 3사분면
                    else if (first.first < second.first && first.second > second.second) {
                        if (second.first - i <= first.first && second.second >= first.second - j) continue;
                        else if (second.second + i >= first.second && second.first <= first.first + j) continue;
                        cout << ans;
                        return 0;
                    }
                        // first 기준으로 second가 4사분면
                    else if (first.first > second.first && first.second > second.second) {
                        if (second.first + i >= first.first && second.second >= first.second - j) continue;
                        else if (second.second + i >= first.second && second.first >= first.first - j) continue;
                        cout << ans;
                        return 0;
                    }
                }
            }
        }
    }
}