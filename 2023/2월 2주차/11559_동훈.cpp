#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cstring>

using namespace std;

int main() {
    string map[12];
    int ans = 0;
    int flag = 0;
    int d[4][2] = {{1,  0},
                   {-1, 0},
                   {0,  1},
                   {0,  -1}};

    for (auto &i: map)
        cin >> i;

    while (true) {
        flag = 0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> v;
        int visited[12][6];
        memset(visited, 0, sizeof(visited));
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.' && visited[i][j] == 0) {
                    char color = map[i][j];
                    q.emplace(i, j);
                    v.emplace_back(i, j);
                    visited[i][j] = 1;
                    while (!q.empty()) {
                        pair<int, int> front = q.front();
                        q.pop();
                        for (auto &k: d) {
                            if (front.first + k[0] < 0 || front.first + k[0] > 11) continue;
                            else if (front.second + k[1] < 0 || front.second + k[1] > 5) continue;
                            if (map[front.first + k[0]][front.second + k[1]] == color &&
                                visited[front.first + k[0]][front.second + k[1]] == 0) {
                                q.emplace(front.first + k[0], front.second + k[1]);
                                visited[front.first + k[0]][front.second + k[1]] = 1;
                                v.emplace_back(front.first + k[0], front.second + k[1]);
                            }
                        }
                    }
                    if (v.size() >= 4) {
                        flag = 1;
                        for (auto p: v) {
                            map[p.first][p.second] = '.';
                        }
                    }
                    v.clear();
                }
            }
        }
         if (flag == 0) break;
        ans++;
        for (int i = 0; i < 6; i++) {
            int p = -1;
            for (int j = 11; j >= 0; j--) {
                if (map[j][i] == '.' && p == -1) p = j;
                else if (map[j][i] != '.' && p != -1) {
                    map[p][i] = map[j][i];
                    map[j][i] = '.';
                    p--;
                }
            }
        }
    }

    cout << ans;

    return 0;
}