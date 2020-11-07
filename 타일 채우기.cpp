#include <iostream>
using namespace std;
int dp[31];
int main() {
	int N;
	cin >> N;
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= N; i++) {
		if (i % 2 == 0) {
			dp[i] = 3 * dp[i - 2];
			for (int j = i - 4; j >= 0; j = j - 2) {
				dp[i] += 2 * dp[j];
			}
		}
	}
	cout << dp[N];
	return 0;
}