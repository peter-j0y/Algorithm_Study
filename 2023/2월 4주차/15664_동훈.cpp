#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

void print(int idx, int depth, vector<int> ans) {
    if (depth == 0) {
        for (auto i: ans)
            cout << i << " ";
        cout << "\n";
        return;
    }

    int prev = 0;

    for (int i = idx; i < n; i++) {
        if (v[i] == prev) continue;
        ans.emplace_back(v[i]);
        print(i + 1, depth - 1, ans);
        ans.pop_back();
        prev = v[i];
    }

}

int main() {
    cin >> n >> m;

    v.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    print(0, m, vector<int>());

    return 0;
}