#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, ans = 0, input;
    priority_queue<int, vector<int>, greater<>> q;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        q.push(input);
    }

    while (!q.empty()) {
        if (q.size() == 1)
            break;
        else {
            int tmp;
            tmp = q.top();
            q.pop();
            tmp += q.top();
            q.pop();

            ans += tmp;
            q.push(tmp);
        }
    }

    cout << ans;

    return 0;
}