#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int len;
	cin >> len;
	string str;
	cin >> str;
	for (int i = 0; i <= len / 2; i++) {
		if (str[i] == '?' && str[len - i - 1] == '?') {
			str[i] = 'a';
			str[len - i - 1] = 'a';
		}
		else if (str[i] == '?' && str[len - i - 1] != '?') {
			str[i] = str[len - i - 1];
		}
		else {
			str[len - i - 1] = str[i];
		}
	}
	cout << str;
	return 0;
}