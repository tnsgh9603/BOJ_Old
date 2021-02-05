#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string N;
	int n;
	getline(cin, N);
	n = stoi(N);
	for (int t = 1; t <= n; t++) {
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		map<char, int>m;
		int ans = 0;
		for (auto i : s1) {
			m[i]++;
		}
		for (auto i : s2) {
			m[i]--;
		}
		for (auto i : m) {
			ans += abs(i.second);
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}