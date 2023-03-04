#include <iostream>
#include <vector>

using namespace std;

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

#define INT_MAX (1e9 + 1)

vector<int> v(100010, 0);
int maxTree[400010], minTree[400010];

int initMin(int start, int end, int node) {
    if (start == end) return minTree[node] = v[start];

    int mid = (start + end) / 2;
    return minTree[node] = min(initMin(start, mid, node * 2), initMin(mid + 1, end, node * 2 + 1));
}

int initMax(int start, int end, int node) {
    if (start == end) return maxTree[node] = v[start];

    int mid = (start + end) / 2;
    return maxTree[node] = max(initMax(start, mid, node * 2), initMax(mid + 1, end, node * 2 + 1));
}

int findMin(int start, int end, int node, int left, int right) {
    if (left > end || start > right) return INT_MAX;
    if (start >= left && end <= right) return minTree[node];

    int mid = (start + end) / 2;
    int min1 = findMin(start, mid, node * 2, left, right);
    int min2 = findMin(mid + 1, end, node * 2 + 1, left, right);
    return min(min1, min2);
}

int findMax(int start, int end, int node, int left, int right) {
    if (left > end || start > right) return 0;
    if (start >= left && end <= right) return maxTree[node];

    int mid = (start + end) / 2;
    int max1 = findMax(start, mid, node * 2, left, right);
    int max2 = findMax(mid + 1, end, node * 2 + 1, left, right);
    return max(max1, max2);
}

int main() {
    cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    initMin(1, n, 1);
    initMax(1, n, 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << findMin(1, n, 1, a, b) << " " << findMax(1, n, 1, a, b) << "\n";
    }

    return 0;
}
