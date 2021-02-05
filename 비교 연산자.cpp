#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	int a, b, cnt = 0;
	string cal;
	bool c;
	while (1) {
		cin >> a >> cal >> b;
		if (cal == "E") {
			return 0;
		}
		if (cal == ">") {
			c = a > b;
		}
		else if (cal == ">=") {
			c = a >= b;
		}
		else if (cal == "<") {
			c = a < b;
		}
		else if (cal == "<=") {
			c = a <= b;
		}
		else if (cal == "==") {
			c = a == b;
		}
		else if (cal == "!=") {
			c = a != b;
		}
		++cnt;
		cout << "Case " << cnt << ": " << boolalpha << c << "\n";
	}
	return 0;
}
