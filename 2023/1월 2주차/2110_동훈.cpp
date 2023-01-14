#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, c, ans = 0, cnt;
    ll start, end, mid, target;
    vector<ll> v;

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> target;
        v.push_back(target);
    }
    sort(v.begin(), v.end());

    start = 1;
    end = v[n - 1] - v[0];

    while (start <= end) {
        target = v[0];
        mid = (start + end) / 2;
        cnt = 1;
        for (int i = 1; i < n; ++i) {
            if ((v[i] - target) >= mid) {
                ++cnt;
                target = v[i];
            }
        }
        if (cnt >= c) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << ans;
    return 0;
}