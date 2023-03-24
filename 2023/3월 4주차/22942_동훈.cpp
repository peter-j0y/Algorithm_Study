#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int chk = 0;

struct infor {
    int number;
    bool open;
};

struct node {
    node(int i, int i1, bool b) {
        info.number = i;
        position = i1;
        info.open = b;
    }

    int position;
    infor info;
};

bool compare(node a, node b) {
    if (a.position == b.position) {
        chk = 1;
        return a.info.number < b.info.number;
    }
    return a.position < b.position;
}

int main() {
    vector<node> v;
    stack<infor> s;

    int n;
    cin >> n;
    int x, r;
    for (int i = 1; i <= n; i++) {
        cin >> x >> r;
        v.emplace_back(i, x - r, true);
        v.emplace_back(i, x + r, false);
    }

    sort(v.begin(), v.end(), compare);

    if (chk == 0)
        for (auto i: v) {
            if (s.empty()) s.push(i.info);
            else if (i.info.open) s.push(i.info);
            else if (!i.info.open && i.info.number == s.top().number) {
                s.pop();
            } else if (!i.info.open && i.info.number != s.top().number) {
                chk = 1;
                break;
            }
        }
    if (!s.empty()) chk = 1;

    if (chk == 1) cout << "NO";
    else cout << "YES";

    return 0;
}