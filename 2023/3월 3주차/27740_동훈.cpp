#include <iostream>

using namespace std;

int main() {
    int n, prev = 0, a, min = 1e9, way = 0, idx = 0;
    int tmp;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 1) {
            tmp = (n - i + 1) + prev * 2;
            if (tmp < min) idx = prev, min = tmp, way = 0;
            tmp = (n - i + 1) * 2 + prev;
            if (tmp < min) idx = n - i + 1, min = tmp, way = 1;
            prev = i;
        }
    }

    if (prev < min) idx = prev, min = prev, way = 0;

    cout << min << "\n";

    if (way == 0) {
        for (int i = 1; i <= min; i++)
            if (i <= idx) cout << "L";
            else cout << "R";
    } else {
        for (int i = 1; i <= min; i++)
            if (i <= idx) cout << "R";
            else cout << "L";
    }

    return 0;
}
