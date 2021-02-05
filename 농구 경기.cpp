#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[26];
int main() {
	fastio;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		arr[s[0] - 'a']++;
	}
	bool flag = true;
	for (int i = 0; i <= 25; i++) {
		if (arr[i] >= 5) {
			cout << (char)(i + 97);
			flag = false;
		}
	}
	if (flag) {
		cout << "PREDAJA";
	}
	return 0;
}