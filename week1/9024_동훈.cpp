#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());

        int f = 0, r = n - 1;
        int ans = v[f] + v[r];
        int cnt = 0;
        while (f < r) {
            int tmp = v[f] + v[r];
            if (abs(ans - k) > abs(tmp - k)) {
                ans = tmp;
                cnt = 1;
            } else if (abs(ans - k) == abs(tmp - k)) {
                cnt++;
            }
            if (tmp <= k) f++;
            else r--;
        }
        cout << cnt << "\n";
    }
    return 0;
}
