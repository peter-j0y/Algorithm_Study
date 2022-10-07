#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 500000

using namespace std;

vector<int> v;

int calc(int n, int gap, int minus) {
    int cnt = 0, flag = 0;
    int start = n + gap * minus;
    int ans = MAX;

    for (auto j: v) {
        int target = start;
        if (target == 0 && v.front() == 0) flag = 1;
        while (target > 0) {
            if (target % 10 == j) {
                flag = 1;
                break;
            } else target /= 10;
        }
        if (flag == 1) break;
    }

    if (flag == 0) {
        if (start == 0) cnt++;
        else
            while (start > 0) {
                start /= 10;
                cnt++;
            }
        cnt += gap;
        ans = min(ans, cnt);
    }

    return ans;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, input;
    int ans;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    ans = abs(100 - n);

    for (int i = 0; i <= 499900; i++) {
        ans = min(ans, calc(n, i, 1));
        if (n - i >= 0) ans = min(ans, calc(n, i, -1));
    }

    cout << ans;

    return 0;
}