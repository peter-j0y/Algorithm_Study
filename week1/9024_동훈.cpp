#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;
        cout << input[0] << input[input.size() - 1] << "\n";
    }
}