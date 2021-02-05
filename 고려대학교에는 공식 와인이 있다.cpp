#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int c, k, p, koreauniv = 0;
	cin >> c >> k >> p;
	for (int i = 1; i <= c; i++) {
		koreauniv += (k * i) + p * (i * i);
	}
	cout << koreauniv;
	return 0;
}