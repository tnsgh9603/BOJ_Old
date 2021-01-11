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
        // u를 만들기 위해서는 부품 v가 w가 필요
        vec[v].push_back({ u,w });
        arr[u]++;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            // i는 기본 부품이란 것을 check
            check[i] = true;
            q.push(i);
            // need[i][j] -> i를 만들기 위해 필요한 장난감 j의 수를 저장
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