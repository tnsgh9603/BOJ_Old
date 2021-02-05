#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	string a, b;
	getline(cin, a);
	cin >> b;
	for (int i = 0, j = 0; i < a.size(); i++, j++) {
		if (j >= b.size()) {
			j = 0;
		}
		if (a[i] == ' ') {
			cout << " ";
			continue;
		}
		if (a[i] - (b[j] - 96) < 97) {
			printf("%c", 122 - (96 - (a[i] - (b[j] - 96))));
		}
		else {
			printf("%c", a[i] - (b[j] - 96));
		}
	}
	return 0;
}