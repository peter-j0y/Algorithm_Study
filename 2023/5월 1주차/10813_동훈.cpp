#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    while(m--) {
        int a, b;
        cin >> a >> b;

        int tmp = arr[a - 1];
        arr[a - 1] = arr[b - 1];
        arr[b - 1] = tmp;
    }

    for(auto i : arr) {
        cout << i << " ";
    }

    return 0;
}
