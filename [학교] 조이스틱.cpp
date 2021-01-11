#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int sol(string& s) {
	auto f = [&](char c) {
		return min(c - 'A', 'Z' - c + 1);
	};
	int n = s.size();
	int ret = 0, mn = n - 1;
	for (int i = 0; i < n; i++) ret += f(s[i]);

	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] != 'A') {
			v.push_back(i);
		}
	}
	if (v.size() == 0) {
		return 0;
	}
	if (v.size() == 1) {
		return ret + min(v[0], n - v[0]);
	}
	for (int i = 0; i < v.size() - 1; i++) {
		int a = v[i], b = v[i + 1];
		mn = min(mn, 2 * a + (n - b));
		mn = min(mn, 2 * (n - b) + a);
	}
	mn = min(mn, v.back());
	mn = min(mn, n - v.front());
	return ret + mn;
}

int main() {
	fastio;
	string s; cin >> s;
	cout << sol(s) << '\n';
}