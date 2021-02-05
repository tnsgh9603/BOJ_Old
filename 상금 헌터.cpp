#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int T; 	cin >> T;
	while (T--) {
		int a, b , sum = 0; 
		cin >> a >> b;
		if (a == 1) {
			sum = sum + 500;
		}
		else if (2 <= a && a <= 3) {
			sum = sum + 300;
		}
		else if (4 <= a && a <= 6) {
			sum = sum + 200;
		}
		else if (7 <= a && a <= 10) {
			sum = sum + 50;
		}
		else if (11 <= a && a <= 15) {
			sum = sum + 30;
		}
		else if (16 <= a && a <= 21) {
			sum = sum + 10;
		}
		if (b == 1) {
			sum = sum + 512;
		}
		else if (2 <= b && b <= 3) {
			sum = sum + 256;
		}
		else if (4 <= b && b <= 7) {
			sum = sum + 128;
		}
		else if (8 <= b && b <= 15) {
			sum = sum + 64;
		}
		else if (16 <= b && b <= 31) {
			sum = sum + 32;
		}
		cout << sum * 10000 << '\n'; 
	}
	return 0;
}