#include <iostream>
#include <string>

using namespace std;

#define abs(a) (((a) < 0) ? -(a) : (a))
#define min(a, b) a < b ? a : b

int calc(string name) {
    int n = name.length();
    int tmp, prev = 0, min = 1e9;
    for (int i = 1; i <= n; i++) {
        char a = name[i];
        if (a != 'A') {
            tmp = (n - i + 1) + prev * 2;
            if (tmp < min) min = tmp;
            tmp = (n - i + 1) * 2 + prev - 1;
            if (tmp < min) min = tmp;
            prev = i;
        }
    }

    if (prev < min) min = prev;

    return min - 1;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        string name;
        cin >> name;
        int ans = calc(name);
        for (auto i: name) {
            int tmp = abs('A' - i);
            ans += min(tmp, 26 - tmp);
        }
        cout << ans << "\n";
    }
    return 0;
}
