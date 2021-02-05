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
        // 양방향 삽입
        adj[x].push_back({ y,z });
        adj[y].push_back({ x,z });
        // dist 배열 초기화
        dist[x] = INT_MAX;
        dist[y] = INT_MAX;
    }
    // 정점 2부터 정점 2까지의 거리는 0 (기저 사례)
    dist[2] = 0;
    // 기저 사례
    dp[2] = 1;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,2 });
    while (!pq.empty()) {
        int now_vertex = pq.top().second, now_dist = -pq.top().first;
        pq.pop();
        // 같은 정점에 대한 또다른 탐색이 현재 저장된 값을 갱신할 수 없다면 무시
        if (dist[now_vertex] < now_dist) {
            continue;
        }
        for (auto next : adj[now_vertex]) {
            int next_dist = next.second + now_dist;
            int next_vertex = next.first;
            // dist배열에 최소값 대입
            if (next_dist < dist[next_vertex]) {
                dist[next_vertex] = next_dist;
                pq.push({ -next_dist,next_vertex });
            }
            // 탐색중인 정점보다 2번 노드에 가까운 거리의 정점에서 출발하는 경로 개수는 모두 구해놓았기 때문에
            // 이를 이용하여 x번 정점에서 출발하는 경로 개수도 구할 수 있다.

            // 이미 다음 정점에 대한 탐색을 완료하였고, 다음 정점에 대해 구해놓은 거리보다 현재 정점까지의 거리가 더 큰 경우
            if (dist[next_vertex] < now_dist) {
                dp[now_vertex] += dp[next_vertex];
            }
        }
    }
    cout << dp[1];
    return 0;
}