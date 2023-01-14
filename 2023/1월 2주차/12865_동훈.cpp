#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, w, v;

    cin >> n >> k;

    vector<vector<int>> vec(n + 1, vector<int>(k + 1, 0));
    vector<pii> d(n + 1, {0, 0});

    for (int i = 1; i <= n; i++) {
        cin >> w >> v;
        d[i] = {w, v};
    }

    sort(d.begin(), d.end(), cmp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            w = d[i].first;
            v = d[i].second;
            if (j >= w) {
                if (vec[i - 1][j] >= vec[i - 1][j - w] + v)
                    vec[i][j] = vec[i - 1][j];
                else
                    vec[i][j] = vec[i - 1][j - w] + v;
            } else
                vec[i][j] = vec[i - 1][j];
        }
    }

    cout << vec[n][k];

    return 0;
}
