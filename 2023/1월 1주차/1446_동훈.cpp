#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shortcut {
    int start;
    int end;
    int length;
};

bool compare(Shortcut a, Shortcut b) {
    if (a.start == b.start && a.end == b.end) return a.length < b.length;
    else if (a.end == b.end) return a.start < b.start;
    else return a.end < b.end;
}

int main() {
    int n, d, target = 0;
    vector<Shortcut> v;

    Shortcut input{};

    cin >> n >> d;
    vector<int> ans(d + 10);

    for (int i = 0; i < n; i++) {
        cin >> input.start >> input.end >> input.length;

        if (input.end - input.start > input.length && input.end <= d) {
            v.push_back(input);
        }
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 1; i <= d; i++) {
        ans[i] = ans[i - 1] + 1;
        for (; target < v.size(); target++) {
            if (v[target].end == i && ans[i] > ans[v[target].start] + v[target].length) {
                ans[i] = ans[v[target].start] + v[target].length;
            } else if (v[target].end > i) break;
        }
    }

    cout << ans[d];

    return 0;
}