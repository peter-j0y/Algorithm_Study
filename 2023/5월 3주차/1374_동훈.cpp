#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    vector<pii> v;

    while (n--) {
        int num, s, e;
        cin >> num >> s >> e;
        v.emplace_back(s, e);
    }

    sort(v.begin(), v.end());

    for (auto i: v) {
        if (pq.empty()) {
            pq.push(i.second);
        } else {
            if (pq.top() > i.first) {
                pq.push(i.second);
            } else {
                pq.pop();
                pq.push(i.second);
            }
        }
    }

    cout << pq.size();

    return 0;
}
