#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	while (n--) {
		double a;
		cin >> a;
		cout << fixed << setprecision(10) << a / 6 << "\n";
	}
	return 0;
}