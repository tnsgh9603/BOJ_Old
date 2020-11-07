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
		// ��������� �־���
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	// bfs�� dfs�� ���� �θ���� ���̸� ã�´�
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

	// ��Ʈ�� ���ٸ� �̹� ���� Ʈ��
	if (u == v) {
		return;
	}

	if (a > b) { // �� ��� �� ����ȣ�� �������� �θ��尡 �ǵ��� ����
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}
int lca(int u, int v) {
	// u�� v���� �� ���� Ʈ����� swap
	if (level[u] < level[v]) {
		swap(u, v); // �׻� u�� �� ���� Ʈ���� �ǵ��� �Ѵ�. 
	}

	while (level[u] != level[v]) {
		u = parent[u]; //������ ������ �� ���� �θ��带 �־��ش�
	}
	while (u != v){ // �� ������ ������ ������ �θ��带 �־��ش�
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