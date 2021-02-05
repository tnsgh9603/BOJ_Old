#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a ,cnt = 0;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		int sum = 0, temp = i;
		while (temp) {
			sum = sum + temp % 10;
			temp = temp / 10;
		}
		if (i % sum == 0) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}