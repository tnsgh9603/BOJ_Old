#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque <int> st;
int main() {
	int N, num;
	string command;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> command;
		if (command == "push_front") {
			cin >> num;
			st.push_front(num);
		}
		else if (command == "push_back") {
			cin >> num;
			st.push_back(num);
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
		else if (command == "pop_front") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.front() << "\n";
				st.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.back() << "\n";
				st.pop_back();
			}
		}
	}
	return 0;
}