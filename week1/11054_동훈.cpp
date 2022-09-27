#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), sum[2];
    vector<int> dp;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    dp.push_back(v[0]);
    sum[0].push_back(1);
    for (int i = 1; i < n; i++) {
        if (dp.back() < v[i]) {
            dp.push_back(v[i]);
            sum[0].push_back(dp.size());
        } else {
            auto target = lower_bound(dp.begin(), dp.end(), v[i]);
            *target = v[i];
            sum[0].push_back(target - dp.begin() + 1);
        }
    }

    dp.clear();
    dp.push_back(v.back());
    sum[1].push_back(1);
    for (int i = n - 2; i >= 0; i--) {
        if (dp.back() < v[i]) {
            dp.push_back(v[i]);
            sum[1].push_back(dp.size());
        } else {
            auto target = lower_bound(dp.begin(), dp.end(), v[i]);
            *target = v[i];
            sum[1].push_back(target - dp.begin() + 1);
        }
    }
    reverse(sum[1].begin(), sum[1].end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans < sum[0][i] + sum[1][i] ? sum[0][i] + sum[1][i] : ans;
    }

    cout << ans - 1;

    return 0;
}