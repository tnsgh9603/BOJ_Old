#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	while (1) {
		string s;
		cin >> s;
		if (s == "#") {
			break;
		}
		vector<string>v;
		for (int i = 0; i < s.size(); i++) {
			string temp = "";
			for (int j = 0; j < s.size(); j++) {
				if (j != i) {
					temp += s[j];
				}
			}
			v.push_back(temp);
		}
		bool flag = 0;
		for (auto x : v) {
			int cnt = 0;
			for (int i = 0; i < x.size() / 2; i++) {
				if (x[i] == x[x.size() - i - 1]) {
					cnt++;
				}
			}
			if (cnt == x.size() / 2) {
				cout << x << '\n';
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << "not possible\n";
		}
	}
	return 0;
}