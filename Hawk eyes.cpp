#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int num[4] = { 1, 0, 0, 2 };
	char arr[200];
	cin >> arr;
	for (int i = 0; arr[i]; i++) {
		switch (arr[i]) {
		case 'A':
			swap(num[0], num[1]);
			break;
		case 'B':
			swap(num[0], num[2]);
			break;
		case 'C':
			swap(num[0], num[3]);
			break;
		case 'D':
			swap(num[1], num[2]);
			break;
		case 'E':
			swap(num[1], num[3]);
			break;
		case 'F':
			swap(num[2], num[3]);
			break;
		default:
			break;
		}
	}
	int c, d;
	for (int i = 0; i < 4; i++) {
		if (num[i] == 1) {
			c = i + 1;
		}
		if (num[i] == 2) {
			d = i + 1;
		}
	}
	cout << c << "\n" << d;
	return 0;
}