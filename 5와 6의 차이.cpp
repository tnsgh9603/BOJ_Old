#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
	fastio;
	string a, b;
	cin >> a >> b;
	string a1 = a, b1 = b, a2 = a, b2 = b;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '6') {
			a1[i] = '5';
		}
		if (a[i] == '5') {
			a2[i] = '6';
		}
	} 
	for (int i = 0; i < b.size(); i++) { 
		if (b[i] == '6') {
			b1[i] = '5';
		}
		if (b[i] == '5') {
			b2[i] = '6';
		}
	}
	cout << stoi(a1) + stoi(b1) << ' ' << stoi(a2) + stoi(b2);
	return 0;
}
