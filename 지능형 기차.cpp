#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int in, out, cnt = 0, ans = 0;
	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		cnt -= out;
		ans = max(ans, cnt);
		cnt += in;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}