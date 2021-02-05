#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int cnt = 1;
	string s;
	while (getline(cin, s)) {
		if (s == "Was it a cat I saw?") {
			break;
		}
		for (int i = 0; i < s.size(); i = i + cnt + 1) {
			cout << s[i];
		}
		cout << "\n";
		cnt++;
	}
	return 0;
}