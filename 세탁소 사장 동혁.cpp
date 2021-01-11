#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b;
	cin >> a;
	while (a--) {
		cin >> b;
		cout << b / 25;
		b %= 25;
		cout << " " << b / 10;
		b %= 10;
		cout << " " << b / 5;
		b %= 5;
		cout << " " << b << "\n";
	}
	return 0;
}