#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector <int> vec;
int main() {
	fastio;
	int p, q;
	cin >> p >> q;
	for (int i = 1; i <= p; i++) {
		if (p % i == 0) {
			vec.push_back(i);
		}
	}
	if (q > vec.size()) {
		cout << 0;
	}
	else {
		cout << vec[q - 1];
	}
	return 0;
}