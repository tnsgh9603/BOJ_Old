#include <iostream>
#include <vector>
#include <queue> // priority_queue를 쓰기 위해 필요
#define max 200000000 // infinity를 표현하기 위해
using namespace std;

vector< pair<int, int>> arr[20001]; // 2차원 배열을 20001개 만듬
vector<int> V;
int way[1001] = { 0, };
vector<int> dijkstra(int start, int V)
{
    vector<int> dist(V, max); // dist 벡터를 V크기 만큼 max로 초기화
    dist[start] = 0; // 시작점은 시작점까지와의 거리가 0이므로
    priority_queue<pair<int, int>> pq; //priority_queue 선언

    pq.push(make_pair(0, start)); //쌍으로 만들어서 넣어줌
    while (!pq.empty()) //비어있을때까지 반복
    {
        int cost = -pq.top().first; // -하는 이유는 밑에 있음
        int here = pq.top().second; // 현재 정점의 위치

        pq.pop();

        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸것을 무시한다.
        if (dist[here] < cost) {
            continue;
        }
        //dist[here]은 시작지점으로부터 here 노드까지의 최단비용

        // 인접한 정점들을 모두 검사.
        for (int i = 0; i < arr[here].size(); i++)
        {
            int there = arr[here][i].first;
            int nextDist = cost + arr[here][i].second;

            // 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                way[there] = here;
                pq.push(make_pair(-nextDist, there));
                /*
                    여기서 -로 넣는 이유?
                    priority_queue STL은 기본적으로 가장 큰 원소가 위로 가도록 큐를 구성
                    따라서 거리의 부호를 바꿔서 거리가 작은 정점부터 꺼내지도록 하기 위함
                */
            }
        }
    }
    return dist;
}
int main()
{
    // 정점의 개수, 간선의 개수, 시작정점을 입력받는다.
    int vertex, edge, start_, end_;
    cin >> vertex >> edge;

    vertex++; // 정점의 개수가 1부터 시작하면 V++해준다. 벡터는 0부터 시작하는데 0이라는 정점은 없으므로 ++해줌.

    for (int i = 0; i < edge; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        arr[from].push_back(make_pair(to, weight));
        //입력 받은 것을 쌍으로 만들어서 arr에 넣어줌
    }

    cin >> start_ >> end_;

    vector<int> ans = dijkstra(start_, vertex);

    cout << ans[end_] << "\n";

    vector <int> wayback;
    while (end_) {
        wayback.push_back(end_);
        end_ = way[end_];
    }
    cout << wayback.size() << "\n";
    for (int i = wayback.size() - 1; i >= 0; i--) {
        cout << wayback[i] << " ";
    }
    
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int city, bus;
int arr[1001][1001];
int way[1001][1001] = { 0, };
vector <int> V;
void floyd(){
    for (int via = 1; via <= city; via++)
    {
        for (int from = 1; from <= city; from++)
        {
            if (arr[from][via] == -1) { //시작점에서 경유점으로 갈 수 없는 경우는 제외
                continue;
            }
            for (int to = 1; to <= city; to++)
            {
                if (arr[via][to] == -1 || from == to) // 경유점에서 도착점으로 갈 수 없는 경우, 시작점 = 도착점인 경우는 고려x
                    continue;
                if (arr[from][to] == -1 || arr[from][to] > arr[from][via] + arr[via][to]) {
                    //시작점에서 도착점으로 바로가는 길이 없거나
                    //곧장 가는 것보다 경유점을 지나서 가는 것이 더 빠를 경우 업데이트
                    arr[from][to] = arr[from][via] + arr[via][to];
                    way[from][to] = via;
                }
            }
        }
    }
}
void Find_Route(int Start, int End)
{
    if (way[Start][End] == 0)
    {
        V.push_back(Start);
        V.push_back(End);
        return;
    }
    Find_Route(Start, way[Start][End]);
    V.pop_back();
    Find_Route(way[Start][End], End);
}
int main() {
    int start_, end_;
    cin >> city >> bus;
    //for (int i = 0; i < 1001; i++) {
    //    memset(arr[i], -1, sizeof(int) * 1001);
    //}
    fill(arr[0][0], arr[1000][1001], -1);
    for (int i = 1; i <= bus; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (arr[from][to] == -1) {
            arr[from][to] = cost;
        }
        else // 이미 경로가 있는 경우 최소값 선택
            arr[from][to] = min(arr[from][to], cost);
    }
    cin >> start_ >> end_;

    floyd();

    cout << arr[start_][end_] << "\n";

    V.clear();
    Find_Route(start_, end_);
    cout << V.size() << "\n";
    for (int k = 0; k < V.size(); k++) {
        cout << V.at(k) << " ";
    }
    return 0;
}
*/