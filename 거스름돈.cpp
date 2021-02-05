#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	n = 1000 - n;
	cout << n / 500 + n % 500 / 100 + n % 100 / 50 + n % 50 / 10 + n % 10 / 5 + n % 5;
	return 0;
}
