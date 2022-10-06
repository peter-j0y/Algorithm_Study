#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> print;

void recursive(int n, int m, int idx) {
    if (m == 0) {
        for(auto i : print) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if (idx >= n) {
        return;
    }

    for(int i = idx; i < n; i++) {
        print.push_back(v[i]);
        recursive(n, m - 1, i + 1);
        print.pop_back();
    }
}

int main() {
    int n, m;
    int input;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    recursive(n, m, 0);

    return 0;
}