#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool check(int a) {
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	fastio;
	int a, b;
	cin >> a >> b;
	string s1 = to_string(a), s2 = to_string(b);
	b = stoi(s2 + s1);
	if (check(a) && check(b)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}