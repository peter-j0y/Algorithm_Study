#include <iostream>

#define SIZE 4000010
#define MOD 1000000007

using namespace std;

int v[SIZE], tree[SIZE];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = v[start];
    } else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        long tmp = (long) tree[node * 2] % MOD * (long) tree[node * 2 + 1] % MOD;
        tree[node] = (int) (tmp % MOD);
    }
}

void update(int node, int start, int end, int index, int val) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        tree[node] = val;
    } else {
        update(node * 2, start, (start + end) / 2, index, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
        long tmp = (long) tree[node * 2] % MOD * (long) tree[node * 2 + 1] % MOD;
        tree[node] = (int) (tmp % MOD);
    }
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int m1 = query(node * 2, start, (start + end) / 2, left, right);
    int m2 = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    long tmp = (long) m1 % MOD * (long) m2 % MOD;
    return (int) (tmp % MOD);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    init(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        } else {
            cout << query(1, 1, n, b, c) << "\n";
        }
    }

    return 0;
}
