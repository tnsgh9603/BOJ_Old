#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int ans = (int)1e9;
	int from, to, N; 
	cin >> from >> to >> N;
	while (N--) {
		int cost, cityNum; 
		cin >> cost >> cityNum;
		vector<int> city;
		for (int i = 0; i < cityNum; i++) {
			int c; 
			cin >> c;
			if (c == from || c == to) {
				city.push_back(c);
			}
		}
		if (city.size() == 2) {
			if (city[0] == from && city[1] == to) {
				ans = min(ans, cost);
			}
		}
	}
	printf("%d\n", (ans == (int)1e9) ? -1 : ans);
	return 0;
}