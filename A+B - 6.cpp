#include <iostream>
#include <string>
using namespace std;
int main() {
	int T;
	string s;
	cin >> T;
	while (T--) {
		cin >> s;
		cout << int(s[0] - '0') + int(s[2] - '0') << "\n";
	}
	return 0;
}