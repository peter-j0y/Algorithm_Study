#include <iostream>

using namespace std;

int main() {
    int n, len = 64;
    cin >> n;
    int ans = 0;

    while(len > 0) {
        if (len > n) len /= 2;
        else ans++, n -= len;
    }

    cout << ans;

    return 0;
}