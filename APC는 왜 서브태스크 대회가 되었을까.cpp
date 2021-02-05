#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int A, B, res;
int main() {
	fastio;
	int N, L, K;
	cin >> N >> L >> K;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		if (b <= L) {
			B++;
		}
		else if (a <= L) {
			A++;
		}
	}
	int x = min(B, K); 
	B -= x;
	K -= x;
	res += 140 * x;
	if (K) {
		x = min(A, K);
		res += 100 * x;
	}
	cout << res;
	return 0;
}