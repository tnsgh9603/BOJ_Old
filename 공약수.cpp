#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, a, b, c;
	cin >> n;
	if (n == 2) {
		cin >> a >> b;
	}
	else {
		cin >> a >> b >> c;
	}
	for (int i = 1; i <= a; i++) {
		//a와 b만 입력받았을 때, c는 0 
		if (a % i == 0 && b % i == 0 && c % i == 0) { 
			cout << i << "\n";
		}
	}
	return 0;
}