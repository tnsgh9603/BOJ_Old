#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int arr[10001], time[10001];
bool visited[10001];
// 시간을 계산하기 위 road 벡터, 도로 개수를 count하기 위해 필요한 road2 벡터 선언
vector <pair<int, int>> road[10001], road2[10001];
queue <pair<int, int>> q;
queue <int> q2;
int main() {
    int N, M, start, end, cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a도시에서 b도시로 가는데 c의 비용이 든다.
        // 양방향 저장
        road[a].push_back(make_pair(b, c));
        road2[b].push_back(make_pair(a, c));
        arr[b]++;
    }
    cin >> start >> end;

    // 현재 q에는 (출발 도시, 이 도시의 도로를 지나는데 걸리는 시간 = 0)이 저장되어 있음
    q.push(make_pair(start, 0));
    while (!q.empty()) {
        int cur = q.front().first;
        int cur_time = q.front().second;
        q.pop();
        // (다음 도시와, 다음 도시까지 가는데 걸리는 시간)
        // 문제 조건 상 사이클은 없음 -> 위상정렬 사용 가능
        for (int i = 0; i < road[cur].size(); i++) {
            int next = road[cur][i].first;
            int next_time = road[cur][i].second;

            // time[next] -> next의 도시까지 가는데 필요한 시간
            time[next] = max(time[next], cur_time + next_time);
            if (--arr[next] == 0) {
                q.push(make_pair(next, time[next]));
            }
        }
    }


    // 이제 1분도 쉬지 않고 달려야 하는 사람들이 지나는 도로의 개수를 구해보자
    // 도착지점에서부터 시작해서 역추적
    q2.push(end);
    // 겹칠 수 있으므로 visted 배열로 방문 체크를 해줘야 한다.
    visited[end] = true;
    while (!q2.empty()) {
        int Cur = q2.front();
        q2.pop();
        for (int i = 0; i < road2[Cur].size(); i++) {
            int Prev = road2[Cur][i].first;
            int Prevtime = road2[Cur][i].second;
            // cur도시까지 오는 최대 시간에서
            // cur에서 다음 시간을 뺀 값이 time[prev]와 같아야만
            // 즉, 값이 일치해야만 이 루트가 가장 오래 걸리는 경로인 것을 알 수 있다.
            if (time[Cur] - Prevtime == time[Prev]) {
                cnt++;
                if (!visited[Prev]) {
                    visited[Prev] = true;
                    q2.push(Prev);
                }
            }
        }
    }
    cout << time[end] << "\n" << cnt << "\n";
    return 0;
}