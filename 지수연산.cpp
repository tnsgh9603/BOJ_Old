#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	double a = 1;
	cin >> n;
	a = pow(0.5, n);
	printf("%.*f", n, a);
	return 0;
}