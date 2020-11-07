#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> arr[10001];
queue<int> q;

bool visit[10001]; // 방문여부를 저장하는 bool형 배열
int sum[10001]; // 해당 정점(노드)까지의 길이를 저장하는 배열
int Max, Pos; //최대 거리, 최대 거리에 해당하는 노드

void bfs(int pos)
{
    q.push(pos);

    while (!q.empty())
    {
        int here = q.front();

        visit[here] = true;
        q.pop();

        for (int i = 0; i < arr[here].size(); i++)
        {
            // 방문하려고 하는 노드가 아직 방문하지 않은 경우
            if (visit[arr[here].at(i).first] == false)
            {
                // 큐에 노드를 넣어준다.
                q.push(arr[here].at(i).first);

                // 해당하는 노드의 sum은 가중치 + 부모 노드의 누적합 
                sum[arr[here].at(i).first] += arr[here].at(i).second + sum[here];

                // 해당하는 노드의 sum이 최대인지 확인하고 최대이면 갱신해줌
                if (sum[arr[here].at(i).first] > Max)
                {
                    Max = sum[arr[here].at(i).first];
                    Pos = arr[here].at(i).first;
                }
            }
        }
    }
}

int main()
{
    int node, from, to, weight;
    cin >> node;

    for (int i = 1; i < node; i++)
    {
        cin >> from >> to >> weight;

        arr[from].push_back(pair<int, int>(to, weight));
        arr[to].push_back(pair<int, int>(from, weight));
        // 부모노드에서 자식노드로 가는 방향뿐만 아니라 역행하여 탐색하기도 하므로 양방향으로 해준다.
    }

    //1번째 bfs전 초기화 작업
    fill(visit, visit + 10001, 0);
    fill(sum, sum + 10001, 0);
    Max = 0;

    // 1에서부터 가장 멀리 있는 노드 탐색 (node보다 작은 수이기만 하면 1말고 다른 수를 넣어도 무관)
    bfs(1);

    // 2번째 bfs전 초기화 작업
    fill(visit, visit + 10001, 0);
    fill(sum, sum + 10001, 0);
    Max = 0;

    // 2번째 bfs
    bfs(Pos);

    cout << Max;

    return 0;
}