#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, cost, calc, ans = 0;
    int l = 0, r = 0, mid;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (r < v[i]) r = v[i];
    }

    cin >> cost;

    while (l <= r) {
        mid = (l + r) / 2;
        calc = 0;

        for (auto i : v) {
            if (i <= mid) calc += i;
            else calc += mid;
        }

        if (calc > cost) r = mid - 1;
        else {
            l = mid + 1;
            ans = mid;
        }
    }

    cout << ans;

    return 0;
}