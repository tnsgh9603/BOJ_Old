#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, d, e;
	int cnt1, cnt2, cnt3;
	cin >> a >> b >> c >> d >> e;
	if (a % b == 0) {
		cnt1 = a / b * c;
	}
	else {
		cnt1 = (a / b + 1) * c;
	}
	if (a % d == 0) {
		cnt2 = a / d * e;
	}
	else {
		cnt2 = (a / d + 1) * e;
	}
	cout << min(cnt1, cnt2);
	return 0;
}