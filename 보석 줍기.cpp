#include <iostream>
#include <vector>
using namespace std;

int answer = 0, jewelry[101]; // jewelry�迭�� ������ �ִ� ������ ����
bool visited[101][1 << 15]; // [1<<15]�� �ֿ� �������� üũ
vector <pair<int,int>> graph[101]; // [101]������ ���� ��, pair�� ù ��° ��Ҵ� ���� ��,
// �� ��° ��Ҵ� ���� ���� ���� ���� �մ� �ٸ��� ������ ��, ��� ���� �� �ִ� �ִ� ���� ��
void dfs(int current, int bit, int cnt) {
	// �ٽ� 1�� �������� ��, answer�� �ִ밪 ��� ����
	if (current == 1 && answer < cnt) {
		answer = cnt;
	}
	// �湮 ǥ��
	visited[current][bit] = true;

	for (pair<int,int> next : graph[current]) {
		// ������ ��� �ٸ��� ������ �� �ִ� ������ �ִ뷮���� ���� ��� �ִ� ������ ���� �� ���� ��� ����
		if (next.second < cnt) {
			continue;
		}
		// �ش� ������ �湮�� ���� ���ٸ� �湮 (������ �ִ� ���ε� ������ �� �ֿ� ��� + ������ ���� ���� ���)
		if (!visited[next.first][bit]) {
			dfs(next.first, bit, cnt);
		}
		// ������ �ִ� ���� �湮 
		if (jewelry[current]) {
			// ������ ��� �ٸ��� ������ �� �ִ� ������ �ִ뷮���� ���� ��� �ִ� ������ ���� �� ���� ��� ����  
			if (next.second < cnt + 1) {
				continue;
			}
			// �ٸ��� ���� �� �ְ�, ���� ������ ��� �ش� ������ �湮�� ���� ���ٸ�
			if (!visited[next.first][bit | (1 << jewelry[current])]) {
				dfs(next.first, bit | (1 << jewelry[current]), cnt + 1);
			}
		}
	}
}
int main() {
	// n : ���� ����, m : �ٸ��� ����, K : ������ �ִ� ���� ����
	int n, m, K;
	cin >> n >> m >> K;
	int from, to, temp, jewelrycnt = 1;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		// jewelry�迭�� ������ �ִ� ������ ����
		// ������ ��ȣ�� jewelrycnt++�� ���� ���Ƿ� �ο���
		jewelry[temp] = jewelrycnt++;
	}
	for (int i = 0; i < m; i++) {
		// temp -> �ٸ��� �ǳ� �� ��� ���� �� �ִ� �ִ� ������ ����
		cin >> from >> to >> temp;
		// ��������� 
		graph[from].push_back(make_pair(to, temp));
		graph[to].push_back(make_pair(from, temp));
	}
	graph[1].push_back(make_pair(1,14));

	dfs(1, 0, 0);
	cout << answer;
	return 0;
}