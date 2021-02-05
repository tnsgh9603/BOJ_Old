#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int INF = 1111111111;
int N, K;
int num1 = INF, num2 = INF;
bool flag;
int main() {
	fastio;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		if (num == -1) {
			flag = true;
			continue;
		}
		if (!flag) {
			num1 = min(num1, num);
		}
		else {
			num2 = min(num2, num);
		}
	}
	cout << num1 + num2;
	return 0;
}