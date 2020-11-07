#include <iostream>
#include <vector>
#include <queue> // priority_queue�� ���� ���� �ʿ�
#define max 200000000 // infinity�� ǥ���ϱ� ����
using namespace std;

vector< pair<int, int>> arr[20001]; // 2���� �迭�� 20001�� ����
vector<int> V;
int way[1001] = { 0, };
vector<int> dijkstra(int start, int V)
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
                way[there] = here;
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
    int vertex, edge, start_, end_;
    cin >> vertex >> edge;

    vertex++; // ������ ������ 1���� �����ϸ� V++���ش�. ���ʹ� 0���� �����ϴµ� 0�̶�� ������ �����Ƿ� ++����.

    for (int i = 0; i < edge; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        arr[from].push_back(make_pair(to, weight));
        //�Է� ���� ���� ������ ���� arr�� �־���
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
            if (arr[from][via] == -1) { //���������� ���������� �� �� ���� ���� ����
                continue;
            }
            for (int to = 1; to <= city; to++)
            {
                if (arr[via][to] == -1 || from == to) // ���������� ���������� �� �� ���� ���, ������ = �������� ���� ���x
                    continue;
                if (arr[from][to] == -1 || arr[from][to] > arr[from][via] + arr[via][to]) {
                    //���������� ���������� �ٷΰ��� ���� ���ų�
                    //���� ���� �ͺ��� �������� ������ ���� ���� �� ���� ��� ������Ʈ
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
        else // �̹� ��ΰ� �ִ� ��� �ּҰ� ����
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