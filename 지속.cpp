#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	int cnt = 0;
	if (n >= 10) {
		while (1) {
			cnt++;
			string s = to_string(n);
			int temp = 1;
			for (int i = 0; i < s.size(); i++) {
				temp *= s[i] - '0';
			}
			if (temp < 10) {
				break;
			}
			n = temp;
		}
	}
	cout << cnt;
	return 0;
}