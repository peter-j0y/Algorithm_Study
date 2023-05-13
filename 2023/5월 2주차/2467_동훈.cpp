#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    int minl, minr;
    int min = 2147483647;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int l = 0, r = n - 1;

    while (l < r) {
        int calc = v[l] + v[r];
        if (abs(calc) < min) {
            min = abs(calc);
            minl = l;
            minr = r;
        }
        if (calc < 0) l++;
        else r--;
    }

    cout << v[minl] << " " << v[minr];

    return 0;
}
