#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() { 
	fastio;
	int arr[6] = { 0, 1, 2, 6, 24, 120 };
	while (1) {
		string s; 
		int len, sum = 0;
		cin >> s;
		if (s == "0") {
			break;
		}
		len = s.length();
		for (int i = 0; i < len; i++) {
			sum += arr[len - i] * (s[i] - '0');
		}
		cout << sum << '\n';
	} 
	return 0;
}
