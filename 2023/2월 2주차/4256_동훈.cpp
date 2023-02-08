#include <iostream>

using namespace std;

int a[1001], b[1001];

void recursive(int i, int l, int r) {
    if (l == r) {
        cout << a[i] << " ";
    } else if (l < r) {
        int tmp = b[a[i]];
        recursive(i + 1, l, tmp - 1);
        recursive(i + tmp - l + 1, tmp + 1, r);
        cout << a[i] << " ";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            b[tmp] = i;
        }
        recursive(1, 1, n);
        cout << "\n";
    }
    return 0;
}
