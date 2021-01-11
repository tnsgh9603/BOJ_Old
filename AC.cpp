#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
using namespace std;
deque <int> d;
int main() {
	int ts,n;
	string s,arr;
	bool reverse,error;

	cin >> ts;
	while (ts--) {
		d.clear();
		int num = 0;
		reverse = false;
		error = false;

		cin >> s;
		cin >> n;
		cin >> arr;

		// 입력 배열에서 맨 앞의 '['와 ']'제거
		arr = arr.substr(1, arr.size() - 2);

		for (int i = 0; i < arr.size(); i++) {
			// a.compare(b) a와 b가 동일하면 0을 반환, a가 b보다 사전순으로 빠르면 -1, b가 a보다 사전순으로 빠르면 1 반환

			if (stoi(arr.substr(i, 1)) != 0 || arr.substr(i, 1).compare("0") == 0) {
				num *= 10;
				num += stoi(arr.substr(i, 1));
			}
			else {
				d.push_back(num);
				num = 0;
			}
		}

		if (num != 0) {
			d.push_back(num);
		}

		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'R') {
				reverse = !reverse;
			}
			else if (s[i] == 'D') {
				if (d.empty()) {
					error = true;
					break;
				}
				if (reverse == true) {
					d.pop_back();
				}
				else {
					d.pop_front();
				}
			}
		}

		if (error) {
			cout << "error" << endl;
			continue;
		}

		cout << "[";
		if (!reverse) {
			while (d.size()) {
				cout << d.front();
				d.pop_front();
				if (d.size()) {
					cout << ",";
				}
			}
		}
		else {
			while (d.size()) {
				cout << d.back();
				d.pop_back();
				if (d.size()) {
					cout << ",";
				}
			}
		}
		cout << "]" << endl;
	}

	return 0;
}