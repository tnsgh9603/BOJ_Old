#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A') {
			ans += (s[i] - 'A' + 10) * pow(16, s.length() - i - 1);
		}
		else {
			ans += (s[i] - '0') * pow(16, s.length() - i - 1);
		}
	}
	cout << ans;
	return 0;
}