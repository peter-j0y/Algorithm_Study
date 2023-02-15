#include <iostream>

using namespace std;

typedef long long ll;

#define N 1000001

ll seg[4 * N], num[N];

ll init(int start, int end, int root) {
    if (start == end) return seg[root] = num[start];

    int mid = (start + end) / 2;

    seg[root] = init(start, mid, root * 2)
            + init(mid + 1, end, root * 2 + 1);

    return seg[root];
}

void change(int start, int end, int root, int index, ll target) {
    if (index < start || index > end) return;

    int mid = (start + end) / 2;
    seg[root] += target;

    if (start < end) {
        change(start, mid, root * 2, index, target);
        change(mid + 1, end, root * 2 + 1, index, target);
    }
}

ll sum(int start, int end, int root, int left, int right) {
    if (right < start || left > end) return 0;
    if (left <= start && right >= end) return seg[root];

    int mid = (start + end) / 2;

    return sum(start, mid, root * 2, left, right)
           + sum(mid + 1, end, root * 2 + 1, left, right);
}

int main() {
    int n, m, k;
    int a, b;
    ll c;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    init(0, n - 1, 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            change(0, n - 1, 1, b - 1, c - num[b - 1]);
            num[b - 1] = c;
        } else {
            cout << sum(0, n - 1, 1, b - 1, c - 1) << "\n";
        }
    }

    return 0;
}