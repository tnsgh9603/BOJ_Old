#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string S, arr[55];
int n, m, x, y;
int main() {
	fastio;
	int i, j, s, r, p;
	cin >> m >> S >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (i = 0; i < m; i++) {
		s = 0, r = 0, p = 0;
		for (j = 0; j < n; j++) {
			if (arr[j][i] == 'S') {
				s++;
			}
			else if (arr[j][i] == 'R') {
				r++;
			}
			else {
				p++;
			}
		}
		if (S[i] == 'S') {
			x += p * 2 + s;
		}
		else if (S[i] == 'R') {
			x += s * 2 + r;
		}
		else {
			x += r * 2 + p;
		}
		y += max(max(p * 2 + s, s * 2 + r), r * 2 + p);
	}
	cout << x << "\n" << y;
	return 0;
}