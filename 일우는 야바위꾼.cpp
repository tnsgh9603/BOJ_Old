#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N, X, K, A, B;
	cin >> N >> X >> K;
	for (int i = 0; i < K; i++) {
		cin >> A >> B;
		if (A == X) {
			X = B;
		}
		else if (B == X) {
			X = A;
		}
	}
	cout << X << "\n";
	return 0;
}