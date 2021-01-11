#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int depth[100001], parent[100001][17];
bool visited[100001];
vector<int> vec[100001];
vector<pair<int, int> > tmp; // 깊이와 노드 저장
bool cmp(pair<int, int> a, pair<int, int> b) {
	// 내림차순 정렬
	return a.first > b.first;
}
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
	for (int i = 16; i >= 0; i--) {
		int diff = depth[y] - depth[x];
		if ((diff >= (1 << i))) {
			y = parent[y][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 16; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= 16; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int root, a, b; 
		cin >> root >> a >> b;
		int root_a, root_b, a_b;
		root_a = lca(root, a);
		root_b = lca(root, b);
		a_b = lca(a, b);
		tmp.push_back({ depth[root_a], root_a });
		tmp.push_back({ depth[root_b], root_b });
		tmp.push_back({ depth[a_b], a_b });
		// 서로의 lca중 가장 깊이가 큰 것이 루트노드가 root일때의 a와 b의 lca
		sort(tmp.begin(), tmp.end(), cmp);
		cout << tmp[0].second << "\n";
		tmp.clear();
	}
}