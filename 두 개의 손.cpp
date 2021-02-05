#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	vector<int> v(4);
	for (int i = 0; i < 4; i++) {
		char c;
		cin >> c;
		v[i] = (c != 'P' ? c == 'S' ? 0 : 1 : 2);
	}
	if (v[0] == v[1] && ((v[0] + 1) % 3 == v[2] || (v[0] + 1) % 3 == v[3])) {
		cout << "TK" << '\n';
	}
	else if (v[2] == v[3] && ((v[2] + 1) % 3 == v[0] || (v[2] + 1) % 3 == v[1])) {
		cout << "MS" << '\n';
	}
	else {
		cout << '?' << '\n';
	}
	return 0;
}