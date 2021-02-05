#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char arr[7] = { ' ','!','$','%','(',')','*' };
string s[7] = { "%20","%21","%24","%25","%28","%29","%2a" };
int main() {
	fastio;
	while (1) {
		string a;
		getline(cin, a);
		if (a[0] == '#') {
			break;
		}
		for (auto it : a) {
			int t = 1;
			for (int i = 0; i < 7; i++) {
				if (arr[i] == it) {
					cout << s[i];
					t = 0;
					break;
				}
			}
			if (t) {
				cout << it;
			}
		}
		cout << "\n";
	}
	return 0;
}