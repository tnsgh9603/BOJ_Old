#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
	fastio;
	vector<int> v(10), w(10);
	for (int i = 0; i < 10; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> w[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	sort(w.begin(), w.end(), greater<int>());
	cout << v[0] + v[1] + v[2] << ' ' << w[0] + w[1] + w[2];
	return 0;
}