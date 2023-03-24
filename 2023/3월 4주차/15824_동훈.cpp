#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int div = 1e9 + 7;
    long long ans = 0, sum = 0;
    long long mul = 1;
    vector<int> v;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        sum += (v[v.size() - i - 1] % div - v[i] % div + div) % div;
        sum %= div;
        ans += (sum * (mul % div)) % div;
        mul <<= 1;
        mul %= div;
        ans %= div;
    }

    cout << ans % div;

    return 0;
}