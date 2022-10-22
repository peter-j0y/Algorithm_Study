#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input, target;
    stack<char> base, tmp;
    bool flag;

    cin >> input >> target;

    for (auto i: input) {
        flag = true;
        base.push(i);
        for (auto j = target.rbegin(); j != target.rend(); j++) {
            if (base.empty() || base.top() != *j) {
                while (!tmp.empty()) {
                    base.push(tmp.top());
                    tmp.pop();
                }
                flag = false;
                break;
            } else {
                tmp.push(base.top());
                base.pop();
            }
        }
        if (flag) {
            while (!tmp.empty()) tmp.pop();
        }
    }
    string ans;
    if (base.empty())
        ans = "FRULA";
    else {
        while (!base.empty()) {
            ans += base.top();
            base.pop();
        }
        reverse(ans.begin(), ans.end());
    }
    cout << ans;

    return 0;
}