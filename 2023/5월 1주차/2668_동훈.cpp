#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n;
    int input[101], visited[101];
    vector<int> ans;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i];

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        int cur = i;
        while (!visited[cur]) {
            visited[cur] = i;
            cur = input[cur];
        }
        if (cur == i) {
            do {
                cur = input[cur];
                ans.push_back(cur);
            } while (cur != i);
        } else {
            cur = i;
            while (visited[cur] == i) {
                visited[cur] = 0;
                cur = input[cur];
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int i: ans)
        cout << i << "\n";

    return 0;
}
