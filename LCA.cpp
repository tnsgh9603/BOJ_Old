#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec[50001];
int parent[50001];
int depth[50001];

void dfs(int parentNode, int currentDepth) {
	depth[parentNode] = currentDepth++;
	for (int nextNode : vec[parentNode]) {
		if (!depth[nextNode]) {
			parent[nextNode] = parentNode;
			dfs(nextNode, currentDepth);
		}
	}
}

void bfs(int parentNode, int currentDepth) {
	queue<int> q;
	q.push(parentNode);
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int currentNode = q.front();
			depth[currentNode] = currentDepth;
			q.pop();
			for (int nextNode : vec[currentNode]) {
				if (!depth[nextNode]) {
					parent[nextNode] = currentNode;
					q.push(nextNode);
				}
			}
		}
		currentDepth++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		// 양방향으로 넣어줌
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	// bfs나 dfs를 통해 부모노드와 깊이를 찾는다
	//dfs(1,1);
	bfs(1, 1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int c, d;
		cin >> c >> d;
		if (depth[c] < depth[d]) {
			swap(c, d);
		}
		while (depth[c] != depth[d]) {
			c = parent[c];
		}
		while (c != d) {
			c = parent[c], d = parent[d];
		}
		cout << c << "\n";
	}
	return 0;
}
/*#include <iostream>
#include <algorithm>
using namespace std;
int parent[50001];
int level[50001];
int N, M;
void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		level[i] = 1;
	}
}
int find_parent(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find_parent(parent[a]);
	}
}

void union_parent(int a, int b) {
	int u = find_parent(a);
	int v = find_parent(b);

	// 루트가 같다면 이미 같은 트리
	if (u == v) {
		return;
	}

	if (a > b) { // 두 노드 중 노드번호가 작은것이 부모노드가 되도록 설정
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}
int lca(int u, int v) {
	// u가 v보다 더 깊은 트리라면 swap
	if (level[u] < level[v]) {
		swap(u, v); // 항상 u가 더 작은 트리가 되도록 한다. 
	}

	while (level[u] != level[v]) {
		u = parent[u]; //레벨이 같아질 때 까지 부모노드를 넣어준다
	}
	while (u != v){ // 두 정점이 같아질 때까지 부모노드를 넣어준다
		u = parent[u];
		v = parent[v];
	}
	return u;
}
int main() {
	init();
	int N, M, from, to;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> from >> to;
		union_parent(from, to);
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> from >> to;
		cout << lca(from, to) << "\n";
	}
	return 0;
}*/