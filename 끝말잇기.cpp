#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <int> vec;
int main() {
	int a;
	cin >> a;
	string s;
	bool flag = true;
	while (a--) {
		cin >> s;
		vec.push_back(s[0]);
		for (int i = 0; i < vec.size() -1; i++) {
			if (vec[i] != vec[i + 1]) {
				flag = false;
			}
		}
	}
	if (flag) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}