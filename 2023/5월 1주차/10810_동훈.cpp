#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n, 0);

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;

        for(int i = a - 1; i < b; i++) {
            arr[i] = c;
        }
    }

    for(auto i : arr) {
        cout << i << " ";
    }

    return 0;
}
