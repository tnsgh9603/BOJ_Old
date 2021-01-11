#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, temp, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		cnt += temp - 1;
	}
	cout << cnt + 1;
	return 0;
}