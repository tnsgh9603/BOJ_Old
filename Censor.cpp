#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string out;
		while (ss >> out) {
			if (out.size() == 4) {
				cout << string(4, '*') << ' ';
			}
			else {
				cout << out << ' ';
			}
		}
		if (n) {
			cout << "\n\n";
		}
	}
	return 0;
}