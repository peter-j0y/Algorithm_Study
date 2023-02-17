#include <iostream>
#include <vector>

#define max(a, b) a > b ? a : b

using namespace std;

int main() {
    int n, t, p;
    int top = 0;
    vector<int> v;

    cin >> n;
    v.push_back(0);

    while (n--) {
        cin >> t >> p;
        top = max(top, v.front());
        v.erase(v.begin());
        while (v.size() < t) {
            v.push_back(top);
        }
        v[t - 1] = max(top + p, v[t - 1]);
    }

    int ans = max(top, v[0]);
    cout << ans;

    return 0;
}