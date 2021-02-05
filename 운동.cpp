#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;

	if (M - m < T) {
		cout << -1;
		return 0;
	}

	int turn = 0, workout = 0, x = m;
	for (turn = 0, workout = 0; workout < N; ++turn) {
		if (x + T <= M) {
			x += T;
			++workout;
		}
		else {
			x = max(x - R, m);
		}
	}

	cout << turn;

	return 0;
}