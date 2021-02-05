#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	string a;
	if (m * n % 3) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	return 0;
}