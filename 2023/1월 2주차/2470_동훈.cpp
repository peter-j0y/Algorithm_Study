#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 2147483647

int main() {
    int n, ans = MAX, input, ans_min, ans_max;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int start = 0, end = n - 1;

    while (start < end) {
        int tmp = v[start] + v[end];
        if (abs(tmp) < ans) {
            ans_min = v[start];
            ans_max = v[end];
            ans = abs(tmp);
        }

        if (tmp == 0)
            break;
        else if (tmp < 0)
            start++;
        else
            end--;
    }

    cout << ans_min << " " << ans_max;

    return 0;
}