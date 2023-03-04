#include <iostream>
#include <string>

using namespace std;

int main() {
    string gear[4];
    int k;

    for (auto &i: gear)
        cin >> i;
    cin >> k;
    while (k--) {
        int a, b, tmp;
        char c, d;
        cin >> a >> b;

        c = gear[a - 1][6];
        d = gear[a - 1][2];

        if (b == 1)
            gear[a - 1] = gear[a - 1][7] + gear[a - 1].substr(0, 7);
        else
            gear[a - 1] = gear[a - 1].substr(1, 7) + gear[a - 1][0];

        tmp = b;
        for (int i = a - 2; i >= 0; i--) {
            if (c == gear[i][2]) break;
            c = gear[i][6];
            tmp = -tmp;
            if (tmp == 1)
                gear[i] = gear[i][7] + gear[i].substr(0, 7);
            else
                gear[i] = gear[i].substr(1, 7) + gear[i][0];
        }

        tmp = b;
        for (int i = a; i < 4; i++) {
            if (d == gear[i][6]) break;
            d = gear[i][2];
            tmp = -tmp;
            if (tmp == 1)
                gear[i] = gear[i][7] + gear[i].substr(0, 7);
            else
                gear[i] = gear[i].substr(1, 7) + gear[i][0];
        }
    }

    int num = 1, ans = 0;

    for (auto i: gear) {
        if (i[0] == '1') ans += num;
        num *= 2;
    }

    cout << ans;

    return 0;
}