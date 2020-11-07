#include <iostream>
#include <vector>
using namespace std;

int INF = 200000000;
vector<pair<long long int, long long int>> adj[501];
long long int dist[501];
int main()
{
    int vertex, edge;
    int from, to, weight, least = INF;
    cin >> vertex >> edge;
    for (int i = 1; i <= edge; i++)
    {
        cin >> from >> to >> weight;
        adj[from].push_back(make_pair(to, weight));
    }
    std::fill(dist, dist + 501, INF);
    dist[1] = 0;

    int n = 1;
    while (n <= vertex)
    {
        for (int i = 1; i <= vertex; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                long long int next = adj[i][j].first;
                long long int nextCost = adj[i][j].second + dist[i];

                if (dist[next] > nextCost && dist[i] != INF){
                    /* 여기서 dist[i] != INF를 하는 이유는
                    해당 정점이 방문되어있는 상태여야 시작 정점에서부터 연결되어 이동할 수 있기 때문*/
                    if (n == vertex) {
                    /* 최단 경로는 같은 정점을 두 번 지날 일이 없다.
                    그래서 최단경로의 간선 개수는 많아야 v-1개인데
                    v번 돌렸을때도 이 if문을 들어온다는 것은
                    음의 사이클이 존재한다는 뜻 */
                        cout << "-1\n";
                        return 0;
                    }
                    dist[next] = nextCost;
                }
            }
        }
        n++;
    }

    for (int i = 2; i <= vertex; i++)
    {
        if (dist[i] == INF) {
            cout << "-1\n";
        }
        else {
            printf("%lld\n", dist[i]);
        }
    }
    return 0;
}