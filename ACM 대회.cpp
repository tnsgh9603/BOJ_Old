#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool ans[26];
int cnt[26], sbm[26];
int main() {
	fastio;
	int t;
	char c;
	string s;
	while (1) {
		cin >> t;
		if (t == -1) {
			break;
		}
		cin >> c >> s;
		int num = c - 'A';
		if (s[0] == 'r') {
			ans[num] = true;
			sbm[num] = t;
		}
		else {
			++cnt[num];
		}
	}
	int problem = 0, penalty = 0;
	for (int i = 0; i < 26; i++) {
		if (ans[i]) {
			++problem;
			penalty += sbm[i] + cnt[i] * 20;
		}
	}
	cout << problem << ' ' << penalty;
	return 0;
}