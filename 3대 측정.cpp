#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> vips;
int main() {
	fastio;
	int N, K, L;
	cin >> N >> K >> L;
	for (int a, b, c, i = 0; i < N; ++i) {
		cin >> a >> b >> c;
		if (a + b + c >= K && a >= L && b >= L && c >= L) {
			vips.push_back(a);
			vips.push_back(b);
			vips.push_back(c);
		}
	}
	cout << vips.size() / 3 << '\n';
	for (int i = 0; i < vips.size(); ++i) {
		cout << vips[i] << ' ';
	}
	return 0;
}
