#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string a;
int b, del;
int main() {
	fastio;
	getline(cin, a);
	b = a.length();
	for (int i = 0; i < b; i++) {
		if (a[i] == '1') {
			del += 500;
		}
		if (a[i] == '2') {
			del += 800;
		}
		if (a[i] == '3') {
			del += 1000;
		}
	}
	cout << 5000 - del;
	return 0;
}