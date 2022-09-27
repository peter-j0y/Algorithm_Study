#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool prime[1000001];

void isprime() {
    for (int n = 2; n <= 1000000; n++) {
        if (prime[n])
            for (int i = n + n; i < 1000000; i += n)
                prime[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(prime, true, sizeof(prime));
    isprime();

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int i;
        for (i = 3; i <= n / 2; i++) {
            if (prime[i] && prime[n - i]) {
                cout << n << " = " << i << " + " << n - i << "\n";
                break;
            }
        }
        if (i > n / 2)
            cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}