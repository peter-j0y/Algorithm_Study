#include <iostream>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int x1, y1, x2, y2;
        int n, cnt = 0, cx, cy, r;

        cin >> x1 >> y1 >> x2 >> y2;

        cin >> n;
        while (n--) {
            cin >> cx >> cy >> r;

            int tmp = 0;
            if ((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) - r * r < 0) tmp++;
            if ((cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) - r * r < 0) tmp++;
            if (tmp == 1) cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}