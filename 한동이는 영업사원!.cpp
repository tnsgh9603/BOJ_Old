#include <iostream>
#include <vector>
using namespace std;
// log 2 (30001) -> 14.xxxx
int depth[30001], parent[30001][15];
bool visited[30001];
vector<int> m_vec, vec[30001];
void dfs(int here, int dep) {
	visited[here] = true;
	depth[here] = dep;
	for (auto next : vec[here]) {
		if (visited[next]) {
			continue;
		}
		dfs(next, dep + 1);
		parent[next][0] = here;
	}
}
int lca(int x, int y) {
	if (depth[x] > depth[y]) {
		swap(x, y);
	}
	for (int i = 14; i >= 0; i--) {
		int diff = depth[y] - depth[x];
		if (diff >= (1 << i)) {
			y = parent[y][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 14; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		// a에서 b를 있는 도로가 존재
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0);
	for (int j = 1; j < 15; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
	cin >> M;
	int start = 1, end, ans = 0;
	while (M--) {
		cin >> end;
		ans += depth[start] + depth[end] - 2 * depth[lca(end, start)];
		start = end;
	}
	cout << ans;
}