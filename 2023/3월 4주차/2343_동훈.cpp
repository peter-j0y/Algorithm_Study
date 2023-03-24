#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v;
    int input, s = 0, e = 0;

    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
        e += input;
        if (s < input) s = input;
    }

    while (s < e) {
        int mid = (s + e) / 2;
        int sum = 0, cnt = 1;

        for (auto i: v) {
            if (sum + i > mid) cnt++, sum = i;
            else sum += i;
        }

        if (cnt <= m) e = mid;
        else s = mid + 1;
    }

    cout << e;

    return 0;
}