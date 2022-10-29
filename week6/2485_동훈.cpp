#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    int interval;
    int start, end;
    cin >> n;

    int past, now;
    cin >> past;
    cin >> now;
    start = past;
    interval = now - past;
    past = now;
    for (int i = 2; i < n; i++) {
        cin >> now;
        end = now;
        interval = gcd(interval, now - past);
    }

    cout << ((end - start) / interval) + 1 - n;

    return 0;
}