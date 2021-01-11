#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int arr[10001], time[10001];
bool visited[10001];
// �ð��� ����ϱ� �� road ����, ���� ������ count�ϱ� ���� �ʿ��� road2 ���� ����
vector <pair<int, int>> road[10001], road2[10001];
queue <pair<int, int>> q;
queue <int> q2;
int main() {
    int N, M, start, end, cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a���ÿ��� b���÷� ���µ� c�� ����� ���.
        // ����� ����
        road[a].push_back(make_pair(b, c));
        road2[b].push_back(make_pair(a, c));
        arr[b]++;
    }
    cin >> start >> end;

    // ���� q���� (��� ����, �� ������ ���θ� �����µ� �ɸ��� �ð� = 0)�� ����Ǿ� ����
    q.push(make_pair(start, 0));
    while (!q.empty()) {
        int cur = q.front().first;
        int cur_time = q.front().second;
        q.pop();
        // (���� ���ÿ�, ���� ���ñ��� ���µ� �ɸ��� �ð�)
        // ���� ���� �� ����Ŭ�� ���� -> �������� ��� ����
        for (int i = 0; i < road[cur].size(); i++) {
            int next = road[cur][i].first;
            int next_time = road[cur][i].second;

            // time[next] -> next�� ���ñ��� ���µ� �ʿ��� �ð�
            time[next] = max(time[next], cur_time + next_time);
            if (--arr[next] == 0) {
                q.push(make_pair(next, time[next]));
            }
        }
    }


    // ���� 1�е� ���� �ʰ� �޷��� �ϴ� ������� ������ ������ ������ ���غ���
    // ���������������� �����ؼ� ������
    q2.push(end);
    // ��ĥ �� �����Ƿ� visted �迭�� �湮 üũ�� ����� �Ѵ�.
    visited[end] = true;
    while (!q2.empty()) {
        int Cur = q2.front();
        q2.pop();
        for (int i = 0; i < road2[Cur].size(); i++) {
            int Prev = road2[Cur][i].first;
            int Prevtime = road2[Cur][i].second;
            // cur���ñ��� ���� �ִ� �ð�����
            // cur���� ���� �ð��� �� ���� time[prev]�� ���ƾ߸�
            // ��, ���� ��ġ�ؾ߸� �� ��Ʈ�� ���� ���� �ɸ��� ����� ���� �� �� �ִ�.
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