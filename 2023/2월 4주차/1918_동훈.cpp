#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define fastio cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);

string a;
stack<char> s;

int compare(char tmp) {
    if (tmp == '(') return 0;
    else if (tmp == '*' || tmp == '/') return 2;
    else if (tmp == '+' || tmp == '-') return 1;
}

int main() {
    fastio

    cin >> a;

    for (char i: a) {
        if (i >= 'A' && i <= 'Z') cout << i;
        else if (i == '(') s.push(i);
        else if (i == ')') {
            while (true) {
                char top = s.top();
                s.pop();
                if (top == '(') break;
                else cout << top;
            }
        } else {
            while (!s.empty() && compare(i) <= compare(s.top())) {
                if (s.top() != '(') cout << s.top();
                s.pop();
            }
            s.push(i);
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}