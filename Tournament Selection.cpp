#include <bits/stdc++.h>
using namespace std;
int main() {
	char a;
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		cin >> a;
		if (a == 'W') {
			cnt++;
		}
	}
	if (cnt >= 5) {
		cout << 1;
	}
	else if (cnt >= 3) {
		cout << 2;
	}
	else if (cnt >= 1) {
		cout << 3;
	}
	else {
		cout << -1;
	}
	return 0;
}