#include <iostream>
#include <vector>
#include <limits.h>
#define INF INT_MAX
using namespace std;
// log 2 (100001) -> 16.xxxxxx
int parent[100001][17], qmax[100001][17], qmin[100001][17], depth[100001];
bool visited[100001];
vector<vector<pair<int, int>>>vec;
void dfs(int here, int dep) {
	visited[here] = true;
	depth[here] = dep;
	for (auto next : vec[here]) {
		if (visited[next.first]) {
			continue;
		}
		dfs(next.first, dep + 1);
		parent[next.first][0] = here;
		qmin[next.first][0] = next.second;
		qmax[next.first][0] = next.second;
	}
}
pair<int, int> lca(int x, int y) {
	int rmin = INF;
	int rmax = -INF;
	if (depth[x] > depth[y]) {
		swap(x, y);
	}
	for (int i = 16; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			rmin = min(rmin, qmin[y][i]);
			rmax = max(rmax, qmax[y][i]);
			y = parent[y][i];
		}
	}
	if (x == y) {
		return{ rmin,rmax };
	}
	for (int i = 16; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			rmin = min(rmin, min(qmin[x][i], qmin[y][i]));
			rmax = max(rmax, max(qmax[x][i], qmax[y][i]));
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	rmin = min(rmin, min(qmin[x][0], qmin[y][0]));
	rmax = max(rmax, max(qmax[x][0], qmax[y][0]));
	return{ rmin,rmax };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;
	vec.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// a에서 b까지의 거리는 c
		vec[a].push_back({ b, c });
		vec[b].push_back({ a, c });
	}
	dfs(1, 0);
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			qmin[i][j] = min(qmin[i][j - 1], qmin[parent[i][j - 1]][j - 1]);
			qmax[i][j] = max(qmax[i][j - 1], qmax[parent[i][j - 1]][j - 1]);
		}
	}
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		pair<int, int> r = lca(a, b);
		cout << r.first << " " << r.second << "\n";
	}
	return 0;
}