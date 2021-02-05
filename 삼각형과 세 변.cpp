#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a) {
			break;
		}
		if (a >= b + c || b >= a + c || c >= a + b) {
			cout << "Invalid\n";
		}
		else if (a == b && b == c) {
			cout << "Equilateral\n";
		}
		else if (a == b || b == c || c == a) {
			cout << "Isosceles\n";
		}
		else {
			cout << "Scalene\n";
		}
	}
	return 0;
}