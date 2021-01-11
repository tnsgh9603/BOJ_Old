#include <iostream>
#include <vector>
using namespace std;
int visited[40001], depth[40001], parent[40001][16], dist[40001];
vector<vector<pair<int, int>>> vec;
void dfs(int here, int dep, int dis) {
    visited[here] = true;
    depth[here] = dep;
    dist[here] = dis;
    for (auto next : vec[here]) {
        if (visited[next.first]) {
            continue;
        }
        dfs(next.first, dep + 1, dis + next.second);
        parent[next.first][0] = here;
    }
}
int lca(int x, int y) {
    if (depth[x] > depth[y]) {
        swap(x, y);
    }
    for (int i = 15; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i)) {
            y = parent[y][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 15; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y, z;
    cin >> n;
    vec.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y >> z;
        // x부터 y까지 가는데의 거리 z
        vec[x].push_back({ y,z });
        vec[y].push_back({ x,z });
    }
    dfs(1, 0, 0);
    for (int j = 1; j < 16; j++) {
        for (int i = 1; i <= n; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
    cin >> m;
    while (m--) {
        cin >> x >> y;
        int qlca = lca(x, y);
        cout << dist[x] + dist[y] - 2 * dist[qlca] << "\n";
    }
    return 0;
}