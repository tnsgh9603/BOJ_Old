#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool visited[1000001];
int K;
string P;
// P가 소수 num으로 나누어 떨어지는지 본다.
bool check(int num) {
	int sum = 0;
	// 주어진 수 P 를 각 자리수별로(큰 자리수부터) 나누어 본다
	for (int i = 0; P[i]; i++) {
		sum = (sum * 10 + (P[i] - '0')) % num;
	}
	if (sum == 0) {
		return true;
	}
	return false;
}
int main() {
	fastio;
	cin >> P >> K;
	bool good = true;
	int ans = 0;
	// P가 K 이하의 소수로 나누어 떨어지는지 본다.
	for (int i = 2; i < K; ++i) {
		if (visited[i]) {
			continue;
		}
		// 소수 i 로 P가 나누어 떨어지는지 여부 체크
		if (check(i)) {
			good = false;
			ans = i;
			break;
		}
		// 소수 아닌애들 지움. 에라토스테네스의 체
		for (int j = 2 * i; j < K; j += i) {
			visited[j] = true;
		}
	}
	if (good) {
		cout << "GOOD" << '\n';
	}
	else {
		cout << "BAD " << ans << '\n';
	}
	return 0;
}