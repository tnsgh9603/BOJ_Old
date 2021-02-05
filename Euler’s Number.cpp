#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
ll f[16]{ 1 };
double v[16]{ 1 };
int main() {
	fastio;
	for (int i = 1; i <= 15; i++) {
		f[i] = f[i - 1] * i;
	}
	for (int i = 1; i <= 15; i++) {
		v[i] = v[i - 1] + 1. / f[i];
	}
	int n;
	cin >> n; 
	n = min(n, 15);
	cout << fixed << setprecision(14) << v[n];
	return 0;
}