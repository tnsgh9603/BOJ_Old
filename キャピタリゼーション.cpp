#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	string a;
	cin >> a;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'j' && a[i + 1] == 'o' && a[i + 2] == 'i') {
			a[i] = 'J';
			a[i + 1] = 'O';
			a[i + 2] = 'I';
		}
	}
	cout << a;
	return 0;
}