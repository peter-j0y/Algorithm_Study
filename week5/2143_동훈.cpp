#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t, n, m, input;
    long long ans = 0;
    vector<int> a, b;
    map<int, int> subA, subB;

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        a.push_back(input);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> input;
        b.push_back(input);
    }

    for (auto i = a.begin(); i != a.end(); i++) {
        int sum = 0;
        for (auto j = i; j != a.end(); j++) {
            sum += *j;
            if (subA.find(sum) == subA.end())
                subA[sum] = 1;
            else
                subA.at(sum)++;
        }
    }

    for (auto i = b.begin(); i != b.end(); i++) {
        int sum = 0;
        for (auto j = i; j != b.end(); j++) {
            sum += *j;
            if (subB.find(sum) == subB.end())
                subB[sum] = 1;
            else
                subB.at(sum)++;
        }
    }

    for (auto i: subA) {
        auto target = subB.find(t - i.first);
        if (target != subB.end()) {
            ans += (long long)i.second * target->second;
        }
    }

    cout << ans;

    return 0;
}