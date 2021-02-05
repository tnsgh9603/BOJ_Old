#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool visited[1000001];
int K;
string P;
// P�� �Ҽ� num���� ������ ���������� ����.
bool check(int num) {
	int sum = 0;
	// �־��� �� P �� �� �ڸ�������(ū �ڸ�������) ������ ����
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
	// P�� K ������ �Ҽ��� ������ ���������� ����.
	for (int i = 2; i < K; ++i) {
		if (visited[i]) {
			continue;
		}
		// �Ҽ� i �� P�� ������ ���������� ���� üũ
		if (check(i)) {
			good = false;
			ans = i;
			break;
		}
		// �Ҽ� �ƴѾֵ� ����. �����佺�׳׽��� ü
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