#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N, M, K, num = 0;
	cin >> N >> M >> K;
	while (1) {
		if (K <= (N - 2 + M - 1) && N >= 2 && M >= 1) {
			N -= 2;
			M -= 1;
			num++;
		}
		else {
			break;
		}
	}
	cout << num;
}