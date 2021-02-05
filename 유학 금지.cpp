#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int conv[128];
int main() {
	fastio;
	for (auto c : "CAMBRIDGE") {
		conv[c] = 1;
	}
	string s; 
	cin >> s;
	for (auto i : s) {
		if (!conv[i]) {
			cout << i;
		}
	}
	return 0;
}
