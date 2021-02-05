#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	cin >> s;
	int ans = -1;
	for (int i = 0; i < s.length(); i++) {
		for (int j = i + 1; j < s.length(); j++) {
			if ((j - i + 1) % 2) {
				continue;
			}
			int sum1 = 0, sum2 = 0;
			for (int q = i; q <= (i + j) / 2; q++) {
				sum1 += s[q];
			}
			for (int w = (i + j) / 2 + 1; w <= j; w++) {
				sum2 += s[w];
			}
			if (sum1 == sum2 && j - i + 1 > ans) {
				ans = j - i + 1;
			}
		}
	}
	cout << ans;
	return 0;
}