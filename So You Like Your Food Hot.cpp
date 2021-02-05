#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int pt1, pt2, p11, p12, p21, p22;
	scanf("%d.%d %d.%d %d.%d", &pt1, &pt2, &p11, &p12, &p21, &p22);
	int pt = 100 * pt1 + pt2, p1 = 100 * p11 + p12, p2 = 100 * p21 + p22;
	vector<int> sols;
	for (int a = 0; p1 * a <= pt; ++a) {
		if ((pt - p1 * a) % p2 == 0) {
			sols.push_back(a);
		}
	}
	if (!sols.empty()) {
		for (int a : sols) {
			cout << a << " " << (pt - p1 * a) / p2 << "\n";
		}
	}
	else {
		cout << "none";
	}
	return 0;
}