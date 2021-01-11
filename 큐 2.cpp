#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue <int> st;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, num;
	string command;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			st.push(num);
		}
		else if (command == "front") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.front() << "\n";
			}
		}
		else if (command == "back") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.back() << "\n";
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
				cout << st.front() << "\n";
				st.pop();
			}
		}
	}
	return 0;
}