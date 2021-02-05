#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int population[11], which[11], n, visited[11], ans = INT_MAX;
vector<int> adj[11];
int dfs(int i) {
	if (visited[i]) {
		return 0;
	}
	visited[i] = 1;
	int ret = population[i];
	for (int a : adj[i]) {
		// 같은 선거구면
		if (which[i] == which[a]) {
			ret += dfs(a);
		}
	}
	return ret;
}
void f(int t) {
	if (t == n + 1) {
		vector<int> v;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				v.push_back(dfs(i));
			}
		}
		if (v.size() == 2) {
			// 최소값 갱신
			ans = min(ans, abs(v[0] - v[1]));
		}
		return;
	}
	which[t] = 0;
	f(t + 1);
	which[t] = 1;
	f(t + 1);
}
int main() {
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> population[i];
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		while (t--) {
			int s;
			cin >> s;
			adj[i].push_back(s);
		}
	}
	f(1);
	cout << (ans == INT_MAX ? -1 : ans);
	return 0;
}