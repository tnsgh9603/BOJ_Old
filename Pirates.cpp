#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	vector<int> v(26);
	int n;
	string s;
	cin >> n >> s;
	for (auto i : s) {
		v[i - 'a']++;
	}
	auto it = max_element(v.begin(), v.end());
	cout << char(it - v.begin() + 'a') << ' ' << *it;
	return 0;
}