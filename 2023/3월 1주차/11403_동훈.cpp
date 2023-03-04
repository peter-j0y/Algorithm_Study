#include <iostream>
#include <queue>

using namespace std;

#define fastio cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);

queue<int> q;

int list[110][110], chk[110][110];

int main() {
    fastio

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> list[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (list[i][j] == 1 && chk[i][j] == 0) {
                q.push(j);
                chk[i][j] = 1;
            }
            while (!q.empty()) {
                int x = q.front();
                if (x == i) {
                    q.pop();
                    if (!q.empty()) x = q.front();
                    else break;
                }
                for (int k = 1; k <= n; k++) {
                    if (list[x][k] == 1 && chk[i][k] == 0) {
                        chk[i][k] = 1;
                        q.push(k);
                        list[i][k] = 1;
                    }
                }
                q.pop();
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << list[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

