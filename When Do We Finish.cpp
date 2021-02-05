#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	while (1) {
		int h1, m1, h2, m2;
		char c;
		cin >> h1 >> c >> m1 >> h2 >> c >> m2;
		if (h1 + m1 + h2 + m2 == 0) {
			break;
		}
		int t_sum = (h1 + h2) * 60 + m1 + m2 , days = t_sum / 1440;
		t_sum %= 1440;
		cout << setfill('0') << setw(2) << t_sum / 60;
		cout << ':';
		cout << setfill('0') << setw(2) << t_sum % 60;
		if (days > 0) {
			cout << " +" << days;
		}
		cout << '\n';
	}
	return 0;
}