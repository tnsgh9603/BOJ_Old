#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	cin >> s;
	vector<int> v(26);
	for (auto i : s) {
		v[i - 'a']++;
	}
	sort(v.rbegin(), v.rend());
	v.erase(find(v.begin(), v.end(), 0), v.end());
	if (v.size() <= 2) {
		cout << 0;
	}
	else {
		cout << accumulate(v.begin() + 2, v.end(), 0);
	}
	return 0;
}