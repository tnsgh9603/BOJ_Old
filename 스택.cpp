#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack <int> st;
int main() {
	int N, num;
	string command;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			st.push(num);
		}
		else if (command == "top") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.top() << "\n";
			}
		}
		else if (command == "size") {
			cout << st.size() << "\n";
		}
		else if (command == "empty") {
			if (st.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (command == "pop") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
	}
	return 0;
}