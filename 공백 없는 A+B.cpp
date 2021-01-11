#include <iostream>
using namespace std;
int main() {
	int a = 0, b = 0;
	string s;
	cin >> s;
	if (s.length() == 4) {
		cout << "20";
		return 0;
	}
	else if (s[0] == '1' && s[1] == '0') {
		a = 10;
		b = s[2] - '0';
	}
	else if (s[1] == '1' && s[2] == '0') {
		b = 10;
		a = s[0] - '0';
	}
	else {
		a = s[0] - '0';
		b = s[1] - '0';
	}
	cout << a + b;
}