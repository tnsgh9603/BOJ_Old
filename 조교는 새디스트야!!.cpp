#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int i, N, tmp, num = 1, cnt = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp != num++) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}