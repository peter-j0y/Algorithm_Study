#include <iostream>
#include <algorithm>

using namespace std;

int parent[1000001];

int find(int node) {
    if (node == parent[node]) return node;
    else return parent[node] = find(parent[node]);
}

void uunion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
        int c, a, b;
        cin >> c >> a >> b;

        if (c == 0) {
            uunion(a, b);
        } else {
            int parentA = find(a), parentB = find(b);

            if (parentA == parentB) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
