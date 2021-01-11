#include <iostream>
#include <string>
using namespace std;
int main() {
	bool flag1 = false, flag2 = false;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '_') {
			flag1 = true;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {
			flag2 = true;
		}	
	}
	if (!flag1 && flag2) {
		for (int i = 0; i < s.length(); i++) {
			if (i != s.length() - 1) {
				s.replace(i, s.length() - i - 1, s.substr(i + 1));
				toupper(s[i]);
			}
		}
	}
	else if (flag1 && !flag2){
		for (int i = 0; i < s.length(); i++) {
			if (i != s.length() - 1) {
				s.replace(i, s.length() - i - 1, s.substr(i + 1));
				toupper(s[i]);
			}
		}
	}
	else {
		cout << "Error!";
		return 0;
	}
	cout << s;
	return 0;
}