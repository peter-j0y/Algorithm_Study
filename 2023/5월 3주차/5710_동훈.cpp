#include <iostream>
#include <cmath>

using namespace std;

int getCost(int mid) {
    int cost = 0;
    if (mid <= 100) {
        cost += mid * 2;
    } else {
        cost += 200;
        if (mid <= 10000) {
            cost += (mid - 100) * 3;
        } else {
            cost += 29700;
            if (mid <= 1000000) {
                cost += (mid - 10000) * 5;
            } else {
                cost += 4950000;
                cost += (mid - 1000000) * 7;
            }
        }
    }

    return cost;
}

int main() {
    while(1) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;

        int usage = 0;
        if (a <= 200) {
            usage += a / 2;
        } else {
            usage += 100;
            if (a <= 29000) {
                usage += (a - 200) / 3;
            } else {
                usage += 9900;
                if (a <= 4979900) {
                    usage += (a - 29900) / 5;
                } else {
                    usage += 990000;
                    usage += (a - 4979900) / 7;
                }
            }
        }

        int l = 0, r = usage / 2;
        while(l <= r) {
            int mid = (l + r) / 2;

            int costA = getCost(mid);
            int costB = getCost(usage - mid);

            if (abs(costB - costA) == b) {
                cout << costA << "\n";
                break;
            } else {
                if (abs(costB - costA) < b) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    }
    return 0;
}
