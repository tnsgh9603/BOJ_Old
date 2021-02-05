#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector <int> vec;
int main() {
	fastio;
	int a, b, c, ans = 1;
	cin >> a >> b;
	while (a--) {
		cin >> c;
		vec.push_back(c);
	}
	for (auto i : vec) {
		if (i == 0) {
			i = 1;
		}
		ans = (ans * i) % b;
	}
	cout << ans % b;
	return 0;
}