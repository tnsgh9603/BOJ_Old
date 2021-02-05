#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	while (1) {
		if (to_string(++n).find('0') == -1) {
			break;
		}
	}
	cout << n;
	return 0;
}