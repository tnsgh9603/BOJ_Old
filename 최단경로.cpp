#include <iostream>
#include <vector>
#include <queue> // priority_queue를 쓰기 위해 필요
#define max 200000000 // infinity를 표현하기 위해
using namespace std;

vector< pair<int, int>> arr[20001]; // 2차원 배열을 20001개 만듬
vector<int> dijkstra(int start, int V, int E)
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
    int vertex, edge, start_edge;
    cin >> vertex >> edge;
    cin >> start_edge;

    vertex++; // 정점의 개수가 1부터 시작하면 V++해준다. 벡터는 0부터 시작하는데 0이라는 정점은 없으므로 ++해줌.

    for (int i = 0; i < edge; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        arr[from].push_back(make_pair(to, weight));
        //입력 받은 것을 쌍으로 만들어서 arr에 넣어줌
    }

    vector<int> ans = dijkstra(start_edge, vertex, edge);

    for (int i = 1; i < vertex; i++) {
        ans[i] == max ? printf("INF\n") : printf("%d\n", ans[i]);
        // ans[i]가 max면 INF출력, 아니면 ans[i]출력
    }
    return 0;
}