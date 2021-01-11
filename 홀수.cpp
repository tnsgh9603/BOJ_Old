#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> vec;
int main() {
	fastio;
	int a;
	for (int i = 0; i < 7; i++) {
		cin >> a;
		if (a % 2 == 1) {
			vec.push_back(a);
		}
	}
	if (vec.size() == 0) {
		cout << -1;
	}
	else {
		sort(vec.begin(), vec.end());
		int sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			sum += vec[i];
		}
		cout << sum << "\n" << vec[0];
	}
	return 0;
}