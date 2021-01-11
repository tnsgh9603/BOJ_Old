#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int mod(string s, int n) {
	long long tmp = 0;
	for (int i = 0; i < s.length(); i++) {
		tmp = tmp * 10 + (s[i] - '0');
		tmp %= n;
	}
	return tmp;
}
int main() {
	fastio;
	string K;
	int L;
	cin >> K >> L;

	for (int i = 2; i < L; i++) {
		if (mod(K, i) == 0) {
			printf("BAD %d\n", i);
			return 0;
		}
	}

	cout << "GOOD\n";
}