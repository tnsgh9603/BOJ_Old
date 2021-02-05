#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector <int> mosquito, cocoon, larva;
int main() {
	string s;
	fastio;
	while (getline(cin, s)) {
		stringstream ss(s);
		int m, p, l, e, r, s, n;
		ss >> m >> p >> l >> e >> r >> s >> n;
		mosquito.clear();
		cocoon.clear();
		larva.clear();
		mosquito.push_back(m);
		cocoon.push_back(p);
		larva.push_back(l);
		for (int i = 1; i <= n; i++) {
			m = cocoon[cocoon.size() - 1] / s;
			p = larva[larva.size() - 1] / r;
			l = mosquito[mosquito.size() - 1] * e;
			mosquito.push_back(m);
			cocoon.push_back(p);
			larva.push_back(l);
		}
		cout << mosquito[mosquito.size() - 1] << "\n";
	}
	return 0;
}