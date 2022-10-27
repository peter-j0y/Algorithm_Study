#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int base[26], check[26];

int checkValid() {
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        int tmp = base[i] - check[i];
        if (tmp >= 0) cnt += tmp;
        else cnt -= tmp;
    }

    return cnt;
}

int main() {
    int n;
    string s;
    int len;
    int ans = 0;

    cin >> n >> s;
    len = s.length();

    for (auto i: s)
        base[i - 'A']++;
    n--;

    while (n--) {
        memset(check, 0, sizeof(check));
        cin >> s;
        for (auto i : s)
            check[i - 'A']++;

        switch(checkValid()) {
            case 0:
            case 1: {
                ans++;
                break;
            }
            case 2: {
                if (len == s.length()) ans++;
                break;
            }
            default: {
                break;
            }
        }
    }

    cout << ans;

    return 0;
}