#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[1001], dist[1001];
vector<pair<int, int>> adj[1001];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        // ����� ����
        adj[x].push_back({ y,z });
        adj[y].push_back({ x,z });
        // dist �迭 �ʱ�ȭ
        dist[x] = INT_MAX;
        dist[y] = INT_MAX;
    }
    // ���� 2���� ���� 2������ �Ÿ��� 0 (���� ���)
    dist[2] = 0;
    // ���� ���
    dp[2] = 1;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,2 });
    while (!pq.empty()) {
        int now_vertex = pq.top().second, now_dist = -pq.top().first;
        pq.pop();
        // ���� ������ ���� �Ǵٸ� Ž���� ���� ����� ���� ������ �� ���ٸ� ����
        if (dist[now_vertex] < now_dist) {
            continue;
        }
        for (auto next : adj[now_vertex]) {
            int next_dist = next.second + now_dist;
            int next_vertex = next.first;
            // dist�迭�� �ּҰ� ����
            if (next_dist < dist[next_vertex]) {
                dist[next_vertex] = next_dist;
                pq.push({ -next_dist,next_vertex });
            }
            // Ž������ �������� 2�� ��忡 ����� �Ÿ��� �������� ����ϴ� ��� ������ ��� ���س��ұ� ������
            // �̸� �̿��Ͽ� x�� �������� ����ϴ� ��� ������ ���� �� �ִ�.

            // �̹� ���� ������ ���� Ž���� �Ϸ��Ͽ���, ���� ������ ���� ���س��� �Ÿ����� ���� ���������� �Ÿ��� �� ū ���
            if (dist[next_vertex] < now_dist) {
                dp[now_vertex] += dp[next_vertex];
            }
        }
    }
    cout << dp[1];
    return 0;
}