#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
stack <string> stack_;
queue <char> q;
int main() {
	string sentence;
	cin >> sentence;
	char a;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == '+') {
			char a = q.front();
			q.pop();
			char b = q.front();
			q.pop();
			q.push("(");
			stack_.push(b);
			stack_.push("+");
			stack_.push(a);
		}
		else if (sentence[i] == '-') {
			sentence[i] == '-';
		}
		else {
			q.push(sentence[i]);
		}
	}
	return 0;
}