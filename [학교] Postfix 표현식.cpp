#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack <string> st;
int main() {
	string sentence, a, b, c;
	cin >> sentence;
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == '+' || sentence[i] == '-') {
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			c = "(" + b + sentence[i] + a + ")";
			st.push(c);
		}
		else {
			st.push(sentence.substr(i, 1));
		}
	}
	cout << st.top();
	return 0;
}