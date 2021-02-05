#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	vector<int> v;
	for (int i = 1; i <= 5; i++) {
		string s;
		cin >> s;
		if (s.find("FBI") != -1) {
			v.push_back(i);
		}
	}
	if (v.size()) {
		for (auto i : v) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	else {
		cout << "HE GOT AWAY!" << '\n';
	}
	return 0;
}
