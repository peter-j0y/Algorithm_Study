#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;

    vector<int> dis(n);
    vector<int> cost(n);
    for (int i = 1; i < n; i++)
        cin >> dis[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    long long min = cost[0];

    for (int i = 1; i < n; i++) {
        ans += min * dis[i];
        if (min > cost[i])
            min = cost[i];
    }

    cout << ans;

    return 0;
}
