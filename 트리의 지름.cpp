#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> arr[10001];
queue<int> q;

bool visit[10001]; // �湮���θ� �����ϴ� bool�� �迭
int sum[10001]; // �ش� ����(���)������ ���̸� �����ϴ� �迭
int Max, Pos; //�ִ� �Ÿ�, �ִ� �Ÿ��� �ش��ϴ� ���

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
            // �湮�Ϸ��� �ϴ� ��尡 ���� �湮���� ���� ���
            if (visit[arr[here].at(i).first] == false)
            {
                // ť�� ��带 �־��ش�.
                q.push(arr[here].at(i).first);

                // �ش��ϴ� ����� sum�� ����ġ + �θ� ����� ������ 
                sum[arr[here].at(i).first] += arr[here].at(i).second + sum[here];

                // �ش��ϴ� ����� sum�� �ִ����� Ȯ���ϰ� �ִ��̸� ��������
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
        // �θ��忡�� �ڽĳ��� ���� ����Ӹ� �ƴ϶� �����Ͽ� Ž���ϱ⵵ �ϹǷ� ��������� ���ش�.
    }

    //1��° bfs�� �ʱ�ȭ �۾�
    fill(visit, visit + 10001, 0);
    fill(sum, sum + 10001, 0);
    Max = 0;

    // 1�������� ���� �ָ� �ִ� ��� Ž�� (node���� ���� ���̱⸸ �ϸ� 1���� �ٸ� ���� �־ ����)
    bfs(1);

    // 2��° bfs�� �ʱ�ȭ �۾�
    fill(visit, visit + 10001, 0);
    fill(sum, sum + 10001, 0);
    Max = 0;

    // 2��° bfs
    bfs(Pos);

    cout << Max;

    return 0;
}