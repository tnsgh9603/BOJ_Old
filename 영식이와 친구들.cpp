#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int pe[1001];
int main() {
	fastio;
	int n, m, l;
	cin >> n >> m >> l;
	int maxR = 1, pre = 1, res = 0;
	pe[pre]++;
	while (maxR != m) {
		if (!pe[pre] % 2) {
			pre = (pre + l) % n;
		}
		else {
			pre = ((pre % n) - (l % n) + n - 1) % n + 1;
		}
		pe[pre]++;
		maxR = max(maxR, pe[pre]);
		res++;
	}
	cout << res;
	return 0;
}