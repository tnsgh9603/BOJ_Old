#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, a, pay1 = 0, pay2 = 0;
	cin >> n;
	while (n--) {
		cin >> a;
		pay1 += ((a / 30) + 1) * 10;
		pay2 += ((a / 60) + 1) * 15;
	}
	if (pay1 < pay2) {
		cout << "Y " << pay1;
	}
	else if (pay1 == pay2) {
		cout << "Y M " << pay1;
	}
	else {
		cout << "M " << pay2;
	}
	return 0;
}