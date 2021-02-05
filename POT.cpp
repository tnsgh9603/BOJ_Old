#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int pow(int a, int b) {
	int n = 1;
	for (int i = 0; i < b; i++) {
		n *= a;
	}
	return n;
}
int main() {
	fastio;
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		int a = p % 10;
		p /= 10;
		sum += pow(p, a);
	}
	cout << sum;
	return 0;
}