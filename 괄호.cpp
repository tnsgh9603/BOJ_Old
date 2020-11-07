#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack <char> st;
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		string sentence;
		cin >> sentence;
		bool flag = true;
		while (!st.empty()) {
			st.pop();
		} 
		for (int k = 0; k < sentence.size(); k++) {
			if (sentence[k] == '(') {
				st.push('(');
			}
			else if (sentence[k] == ')') {
				if (!st.empty()) {
					st.pop();
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag && st.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}