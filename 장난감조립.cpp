#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int need[101][101], arr[101];
bool check[101];
vector<vector<pair<int, int>>> vec;
queue <int> q;
int main() {
    int n, m;
    cin >> n >> m;
    vec.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        // u�� ����� ���ؼ��� ��ǰ v�� w�� �ʿ�
        vec[v].push_back({ u,w });
        arr[u]++;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            // i�� �⺻ ��ǰ�̶� ���� check
            check[i] = true;
            q.push(i);
            // need[i][j] -> i�� ����� ���� �ʿ��� �峭�� j�� ���� ����
            need[i][i] = 1;
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < vec[now].size(); i++) {
            int next = vec[now][i].first;
            int num = vec[now][i].second;
            for (int j = 1; j <= n; j++) {
                need[next][j] += need[now][j] * num;
            }
            if (--arr[next] == 0) {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) {
            cout << i << " " << need[n][i] << "\n";
        }
    }
    return 0;
}