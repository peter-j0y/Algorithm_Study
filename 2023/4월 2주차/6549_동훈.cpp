#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> a;

ll search(int s, int e) {
    if (s == e) {
        return a[s];
    }

    int m = (s + e) / 2;
    ll ret = max(search(s, m), search(m + 1, e));

    int l = m, r = m + 1;
    int h = min(a[l], a[r]);
    ret = max(ret, (ll) h * 2);

    while (s < l || r < e) {
        if (r < e && (l == s || a[l - 1] < a[r + 1])) {
            r++;
            h = min(h, a[r]);
        } else {
            l--;
            h = min(h, a[l]);
        }
        ret = max(ret, (ll) h * (r - l + 1));
    }

    return ret;
}

int main() {
    while (1) {
        int n;
        cin >> n;
        cout << n << "\n";

        if (n == 0) break;

        a.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << search(0, n - 1) << "\n";
    }

    return 0;
}
