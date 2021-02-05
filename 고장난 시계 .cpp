#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	fastio;
	int a, b; cin >> a >> b;
	int t = a * 12;
	if (t % 360 == b) cout << 'O' << '\n';
	else cout << 'X' << '\n';
}