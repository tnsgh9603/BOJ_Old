#include <iostream>
#include <vector>
#include <queue> // priority_queue�� ���� ���� �ʿ�
#define max 200000000 // infinity�� ǥ���ϱ� ����
using namespace std;

vector< pair<int, int>> arr[20001]; // 2���� �迭�� 20001�� ����
vector<int> dijkstra(int start, int V, int E)
{
    vector<int> dist(V, max); // dist ���͸� Vũ�� ��ŭ max�� �ʱ�ȭ
    dist[start] = 0; // �������� �������������� �Ÿ��� 0�̹Ƿ�
    priority_queue<pair<int, int>> pq; //priority_queue ����

    pq.push(make_pair(0, start)); //������ ���� �־���
    while (!pq.empty()) //������������� �ݺ�
    {
        int cost = -pq.top().first; // -�ϴ� ������ �ؿ� ����
        int here = pq.top().second; // ���� ������ ��ġ
  
        pq.pop(); 

        // ���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� �������� �����Ѵ�.
        if (dist[here] < cost) {
            continue;
        }
        //dist[here]�� �����������κ��� here �������� �ִܺ��

        // ������ �������� ��� �˻�.
        for (int i = 0; i < arr[here].size(); i++)
        {
            int there = arr[here][i].first;
            int nextDist = cost + arr[here][i].second;

            // �� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
                /*
                    ���⼭ -�� �ִ� ����?
                    priority_queue STL�� �⺻������ ���� ū ���Ұ� ���� ������ ť�� ����
                    ���� �Ÿ��� ��ȣ�� �ٲ㼭 �Ÿ��� ���� �������� ���������� �ϱ� ����
                */
            }
        }
    }
    return dist;
}

int main()
{
    // ������ ����, ������ ����, ���������� �Է¹޴´�.
    int vertex, edge, start_edge;
    cin >> vertex >> edge;
    cin >> start_edge;

    vertex++; // ������ ������ 1���� �����ϸ� V++���ش�. ���ʹ� 0���� �����ϴµ� 0�̶�� ������ �����Ƿ� ++����.

    for (int i = 0; i < edge; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        arr[from].push_back(make_pair(to, weight));
        //�Է� ���� ���� ������ ���� arr�� �־���
    }

    vector<int> ans = dijkstra(start_edge, vertex, edge);

    for (int i = 1; i < vertex; i++) {
        ans[i] == max ? printf("INF\n") : printf("%d\n", ans[i]);
        // ans[i]�� max�� INF���, �ƴϸ� ans[i]���
    }
    return 0;
}