#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    int a, b;

    cin >> n;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (a = n; a >= 1 && v[a] <= v[a - 1]; a--);
    if (a <= 1)
        cout << "-1";
    else {
        for (b = n; v[b] <= v[a - 1]; b--);
        swap(v[a - 1], v[b]);
        sort(v.begin() + a, v.end());

        for (int i = 1; i <= n; i++)
            cout << v[i] << " ";
    }
    return 0;
}
