#include <iostream>
#include <vector>
using namespace std;
// log2 (100001) -> 16.xxx
int parent[100001][17], depth[100001];
bool visited[100001];
vector<vector<int>> vec;
void dfs(int here, int dep) {
    //방문 여부 저장
    visited[here] = true;
    //차수 저장
    depth[here] = dep;
    for (int next : vec[here]) {
        // 방문했으면 무시
        if (visited[next]) {
            continue;
        }
        // 부모 노드 저장
        parent[next][0] = here;
        dfs(next, dep + 1);
    }
}
int lca(int x, int y) {
    // 깊이가 x쪽이 더 큰 경우 바꿔줌
    if (depth[x] > depth[y]) {
        swap(x, y);
    }
    // 서로 깊이를 맞춰줌
    for (int i = 16; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i)) {
            y = parent[y][i];
        }
    }
    // 입력받은 정점이 서로 같은 경우는 둘 중 하나 리턴
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y;
    cin >> n;
    vec.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(1, 0);
    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    cin >> m;
    while (m--) {
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
    return 0;
}