#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n, awin = 0, bwin = 0;
		cin >> n;
		while (n--) {
			char a, b;
			cin >> a >> b;
			if (a == 'R') {
				if (b == 'P') {
					bwin++;
				}
				else if (b == 'S') {
					awin++;
				}
			}
			else if (a == 'P') {
				if (b == 'R') {
					awin++;
				}
				else if (b == 'S') {
					bwin++;
				}
			}
			else if (a == 'S') {
				if (b == 'R') {
					bwin++;
				}
				else if (b == 'P') {
					awin++;
				}
			}
		}
		if (awin > bwin) {
			cout << "Player 1" << '\n';
		}
		else if (bwin > awin) {
			cout << "Player 2" << '\n';
		}
		else {
			cout << "TIE" << '\n';
		}
	}
}