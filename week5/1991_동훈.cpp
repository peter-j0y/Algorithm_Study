#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct tree {
    char parent;
    char left;
    char right;
};

int idx[30];
vector<tree> v(30);

void preorder(int node) {
    cout << v[node].parent;
    if (v[node].left != '.') preorder(v[node].left - 64);
    if (v[node].right != '.') preorder(v[node].right - 64);
}

void inorder(int node) {
    if (v[node].left != '.') inorder(v[node].left - 64);
    cout << v[node].parent;
    if (v[node].right != '.') inorder(v[node].right - 64);
}

void postorder(int node) {
    if (v[node].left != '.') postorder(v[node].left - 64);
    if (v[node].right != '.') postorder(v[node].right - 64);
    cout << v[node].parent;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    char p, l, r;

    memset(idx, 0, sizeof(idx));
    idx[1] = 1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p >> l >> r;
        v[p - 64] = {p, l, r};
    }

    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);

    return 0;
}