#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b;
	cin >> a >> b;
	int x1, x2, y1, y2;
	if (a % 4 == 0) {
		x1 = a / 4;
	}
	else {
		x1 = a / 4 + 1;
	}
	if (b % 4 == 0) {
		x2 = b / 4;
	}
	else {
		x2 = b / 4 + 1;
	}
	y1 = a % 4;
	y2 = b % 4;
	if (y1 == 0) {
		y1 = 4;
	}
	if (y2 == 0) {
		y2 = 4;
	}
	cout << abs(y2 - y1) + abs(x2 - x1);
	return 0;
}