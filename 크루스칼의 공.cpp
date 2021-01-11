#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parent[200001], parent2[200001][22], level[200001], dist[200001], depth[200001];
bool visited[200001];
vector<pair<int, pair<int, int>>> edge;
vector<vector<int>> vec;
int find(int u) {
    // ��Ʈ ����̸� return u
    if (u == parent[u])
        return u;

    // �� �ܿ��� �ڽ��� ��Ʈ�� ã���� ����.
    return parent[u] = find(parent[u]);
}
void merge(int x, int y) {
    // �̹� ���� Ʈ���� ����
    if (find(x) == find(y)) {
        return;
    }
    parent[find(y)] = find(x);
}
void dfs(int here, int dep) {
    visited[here] = true;
    depth[here] = dep;
    for (auto next : vec[here]) {
        if (visited[next]) {
            continue;
        }
        dfs(next, dep + 1);
        parent2[next][0] = here;
    }
}
int getlca(int x, int y) {
    if (depth[x] > depth[y]) {
        swap(x, y);
    }
    for (int i = 20; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i)) {
            y = parent2[y][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 20; i >= 0; i--) {
        if (parent2[x][i] != parent2[y][i]) {
            x = parent2[x][i];
            y = parent2[y][i];
        }
    }
    return parent2[x][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m;

    // �ʱ�ȭ
    for (int i = 1; i <= n + m; i++) {
        parent[i] = i;
        level[i] = 1;
    }

    vec.resize(n + m + 1);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        // x�� y�� �ִ� ������ �������� z��.
        edge.push_back({ z,{x,y} });
    }

    // ũ�罺Į �˰����� ���� ���� ����� �������� �������� ����
    sort(edge.begin(), edge.end());

    for (int i = n + 1; i <= n + m; i++) {
        int x = edge[i - n - 1].second.first;
        int y = edge[i - n - 1].second.second;
        int z = edge[i - n - 1].first;

        // �̹� ���� Ʈ���� continue
        if (find(x) == find(y)) {
            continue;
        }
        // ���ο� ������ ������ �� �ڽ��� ������ ���̴�.
        level[i] = level[find(x)] + level[find(y)];
        dist[i] = z;
        vec[i].push_back(find(x));
        vec[i].push_back(find(y));
        merge(i, x);
        merge(i, y);
    }
    for (int i = n + m; i > 0; i--) {
        if (!depth[i]) {
            dfs(i, 0);
        }
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n + m; i++)
            parent2[i][j] = parent2[parent2[i][j - 1]][j - 1];
    }
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y)) {
            cout << "-1\n";
            continue;
        }
        int lca = getlca(x, y);
        cout << dist[lca] << " " << level[lca] << "\n";
    }
    return 0;
}