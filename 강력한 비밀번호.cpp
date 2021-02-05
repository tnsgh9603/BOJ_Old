#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int num, low, up, spe, n;
int main() {
	fastio;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			num = 1;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			low = 1;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			up = 1;
		}
		else {
			spe = 1;
		}
	}
	cout << max(4 - num - low - up - spe, 6 - n);
	return 0;
}