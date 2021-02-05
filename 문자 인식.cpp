#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int T;
	cin >> T;
	cin.ignore();
	for (int t = 0; t < T; t++) {
		string line;
		int R = 0, A = 0;
		while (1) {
			getline(cin, line);
			if (line.empty()) {
				break;
			}
			A += line.size();
			for (auto c : line) {
				if (c != '#') {
					R++;
				}
			}
		}
		double p = 100.0 * R / A;
		p = round(p * 10) / 10;
		cout << "Efficiency ratio is " << p << "%." << endl;
	}
	return 0;
}