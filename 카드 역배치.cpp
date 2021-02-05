#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	vector<int> v(21);
	iota(v.begin(), v.end(), 0);
	for (int i = 0; i < 10; i++) {
		int n, m;
		cin >> n >> m;
		reverse(v.begin() + n, v.begin() + m + 1);
	}
	for (int i = 1; i <= 20; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}
