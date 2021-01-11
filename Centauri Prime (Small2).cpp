#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, num = 1;
	cin >> n;
	while (n--) {
		string s, ruler;
		cin >> s;
		if (s[s.length() - 1] == 'y' || s[s.length() - 1] == 'Y') {
			ruler = "nobody";
		}
		else if (s[s.length() - 1] == 'a' || s[s.length() - 1] == 'e' || s[s.length() - 1] == 'i' || s[s.length() - 1] == 'o' || s[s.length() - 1] == 'u' || s[s.length() - 1] == 'A' || s[s.length() - 1] == 'E' || s[s.length() - 1] == 'I' || s[s.length() - 1] == 'O' || s[s.length() - 1] == 'U') {
			ruler = "a queen";
		}
		else {
			ruler = "a king";
		}
		cout << "Case #" << num++ << ": " << s << " is ruled by " << ruler << ".\n";
	}
	return 0;
}