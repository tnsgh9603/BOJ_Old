#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void solve() {
	string str;
	getline(cin, str);
	int alpha[26] = {};
	for (char& c : str) {
		++alpha[c - 'a'];
	}
	auto maxAlp = max_element(alpha, alpha + 26);
	for (int i = 0; i < 26; ++i)
		if (alpha[i] == *maxAlp && i != maxAlp - alpha) {
			cout << "?\n";
			return;
		}
	cout << (char)((maxAlp - alpha) + 'a') << '\n';
}
int main() {
	fastio;
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		solve();
	}
	return 0;
}