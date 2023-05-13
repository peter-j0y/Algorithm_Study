#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[101];

    for (int i = 1; i <= n; i++)
        a[i] = i;

    while (m--) {
        int x, y;
        cin >> x >> y;

        for (int i = 0; i < (y - x + 1) / 2; i++) {
            int temp = a[x + i];
            a[x + i] = a[y - i];
            a[y - i] = temp;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";


    return 0;
}
