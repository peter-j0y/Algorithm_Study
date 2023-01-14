#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    vector<vector<int>> v(2, vector<int>(10, 1));

    cin >> n;

    for (int i = 2; i <= n; i++) {
        vector<int> tmp(11, 0);
        tmp[0] = 1;
        for (int j = 1; j <= 9; j++) {
            tmp[j] = (tmp[j - 1] + v[i - 1][j]) % 10007;
        }
        v.push_back(tmp);
    }

    int ans = 0;
    for(auto i : v[n]) {
        ans += i;
        ans %= 10007;
    }

    cout << ans % 10007;

    return 0;
}
