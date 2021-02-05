#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	cin >> s;
	int size = s.length() / 2 , leftsum = 0, rightsum = 0;
	for (int i = 0; i < size; i++) {
		leftsum += s[i] - 48;
		rightsum += s[i + size] - 48;
	}
	if (leftsum == rightsum) {
		cout << "LUCKY";
	}
	else {
		cout << "READY";
	}
	return 0;
}