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
                    /* ���⼭ dist[i] != INF�� �ϴ� ������
                    �ش� ������ �湮�Ǿ��ִ� ���¿��� ���� ������������ ����Ǿ� �̵��� �� �ֱ� ����*/
                    if (n == vertex) {
                    /* �ִ� ��δ� ���� ������ �� �� ���� ���� ����.
                    �׷��� �ִܰ���� ���� ������ ���ƾ� v-1���ε�
                    v�� ���������� �� if���� ���´ٴ� ����
                    ���� ����Ŭ�� �����Ѵٴ� �� */
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