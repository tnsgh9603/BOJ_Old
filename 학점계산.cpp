#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	cin >> s;
	double ans;
	if (s == "A+") {
		ans = 4.3;
	}
	else if (s == "A0") {
		ans = 4.0;
	}
	else if (s == "A-") {
		ans = 3.7;
	}
	else if (s == "B+") {
		ans = 3.3;
	}
	else if (s == "B0") {
		ans = 3.0;
	}
	else if (s == "B-") {
		ans = 2.7;
	}
	else if (s == "C+") {
		ans = 2.3;
	}
	else if (s == "C0") {
		ans = 2.0;
	}
	else if (s == "C-") {
		ans = 1.7;
	}
	else if (s == "D+") {
		ans = 1.3;
	}
	else if (s == "D0") {
		ans = 1.0;
	}
	else if (s == "D-") {
		ans = 0.7;
	}
	else if (s == "F") {
		ans = 0.0;
	}
	cout << fixed << setprecision(1) << ans;
    return 0;
}