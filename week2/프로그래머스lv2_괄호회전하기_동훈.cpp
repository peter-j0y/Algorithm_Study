#include <string>
#include <stack>

using namespace std;

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.length(); i++) {
		string ss = s.substr(i) + s.substr(0, i);
		stack<char> st;
		bool flag = false;
		for (auto i : ss) {
			if (i == '(' || i == '{' || i == '[')
				st.push(i);
			else if (st.empty()) {
				flag = true;
				break;
			}
			else if (i == ')' && st.top() == '(')
				st.pop();
			else if (i == ']' && st.top() == '[')
				st.pop();
			else if (i == '}' && st.top() == '{')
				st.pop();
			else {
				flag = true;
				break;
			}
		}
		if (!flag && st.empty())
			answer++;
	}

	return answer;
}