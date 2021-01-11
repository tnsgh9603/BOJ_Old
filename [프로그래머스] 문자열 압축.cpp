#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, s2;
	cin >> s;
	int len = s.length(), min_length = len;
	for (int i = 1; i <= len; i++) {
		for (int k = 0; k < len;) {
			int cnt = 1;
			while (k + 2 * i <= len && s.substr(k, i) == s.substr(k + i, i)) {
				cnt++;
				k += i;
			}
			if (cnt != 1) {
				s2.append(to_string(cnt) + s.substr(k, i));
				k += i;
			}
			else {
				s2.append(s.substr(k, i));
				k += i;
			}	
		}
		if (min_length > s2.length()) {
			min_length = s2.length();
		}
		s2.clear();
	}
	cout << min_length;
	return 0;
}