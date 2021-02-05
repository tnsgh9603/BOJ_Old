#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int check_8(int n) {
	int sum = 0;
	string s = to_string(n);
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] < '0' || s[i] >'7') {
			return 0;
		}
		sum += int(pow(8, s.length() - i - 1) * (s[i] - '0'));
	}
	return sum;
}
int check_16(int n) {
	int sum = 0;
	string s = to_string(n);
	for (int i = s.length() - 1; i >= 0; i--) {
		sum += int(pow(16, s.length() - i - 1) * (s[i] - '0'));
	}
	return sum;
}
int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << a << " " << check_8(b) << " " << b << " " << check_16(b) << "\n";
	}
	return 0;
}