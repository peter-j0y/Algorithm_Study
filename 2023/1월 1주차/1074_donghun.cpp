#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, r, c;
    int ans = 0;
    int limX, limY;

    cin >> n >> r >> c;

    limX = limY = pow(2, n) / 2;

    for (; n >= 0; n--) {
        if (r < limX && c < limY) {
            ans += pow(pow(2, n), 2) / 4 * 0;
            limX -= pow(2, n - 1) / 2;
            limY -= pow(2, n - 1) / 2;
        }
        else if (r < limX && c >= limY) {
            ans += pow(pow(2, n), 2) / 4 * 1;
            limX -= pow(2, n - 1) / 2;
            limY += pow(2, n - 1) / 2;
        }
        else if (r >= limX && c < limY) {
            ans += pow(pow(2, n), 2) / 4 * 2;
            limX += pow(2, n - 1) / 2;
            limY -= pow(2, n - 1) / 2;
        }
        else {
            ans += pow(pow(2, n), 2) / 4 * 3;
            limX += pow(2, n - 1) / 2;
            limY += pow(2, n - 1) / 2;
        }
    }

    cout << ans;

    return 0;
}