#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, x, b, y, t;
	cin >> a >> x >> b >> y >> t;
	int fee1, fee2;
	if (t > 30) {
		fee1 = a + (t - 30) * x * 21;
	}
	else {
		fee1 = a;
	}
	if (t > 45) {
		fee2 = b + (t - 45) * y * 21;
	}
	else {
		fee2 = b;
	}
	cout << fee1 << " " << fee2;
	return 0;
}