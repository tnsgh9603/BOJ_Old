#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n1, n2; 
	cin >> n1 >> n2;
	int cnt = 0;
	while (n1 != n2) {
		if (++n1 == 360) {
			n1 = 0;
		}
		cnt++;
	}
	if (cnt <= 180) {
		cout << cnt << "\n";
	}
	else {
		cout << "-" << 360 - cnt << "\n";
	}
	return 0;
}