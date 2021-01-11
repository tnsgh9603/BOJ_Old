#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long n, b;
	cin >> n >> b;
	if (n <= pow(2, b + 1) - 1) {
		cout << "yes\n";
	}
	else {
		cout << "no\n";
	}
}