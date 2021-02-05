#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n; 
	cin >> n;
	cout << string(n, '1') << string(n - 1, '0') << '\n';
	return 0;
}