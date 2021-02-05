#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, i, j;
	do {
		int ans = 0, a = 0, b = 0, len = 0, idx = 0;
		short s[10005];
		char x[1010], y[1010];
		cin >> n;
		if (!n) {
			break;
		}
		cin >> x;
		len = strlen(x);
		memset(y, 0, sizeof(y));
		x[len++] = ',';
		for (i = 0; i <= n; i++) {
			s[i] = 0;
		}
		for (i = 0; i < len; i++) {
			if (x[i] == '-') {
				a = atoi(y);
				idx = 0;
				memset(y, 0, sizeof(y));
				continue;
			}
			else if (x[i] == ',') {
				b = atoi(y);
				idx = 0;
				memset(y, 0, sizeof(y));
				for (j = a > 0 ? a : b; j <= b; j++) {
					s[j] = 1;
				}
				a = b = 0;
				continue;
			}
			y[idx++] = x[i];
		}
		for (i = 1; i <= n; i++) {
			if (s[i]) {
				ans++;
			}
		}
		printf("%d\n", ans);
	} while (n);
	return 0;
}