#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
map <string, bool> visited;
int BFS(string s) {
	// �������� ���� -> ������� �ϴ� ����
	string correct = s;
	sort(correct.begin(), correct.end());
	// pair < ���� ����, �ٲ� Ƚ�� >
	queue<pair<string, int>> Q;
	Q.push(pair<string, int>(s, 0));
	visited[s] = true;

	while (!Q.empty()) {
		string now = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();
		// ���� ������ ��!
		if (now == correct) {
			return cnt;
		}
		// �ٲ� �� �ִ� ��츦 �� �ٲ㺽
		for (int i = 0; i <= N - K; i++) {
			// �߰��κ� ����
			string temp = now.substr(i, K);
			// ��������
			reverse(temp.begin(), temp.end());
			// ���ο�� ����
			string next = now.substr(0, i);
			next += temp;
			// now �� ������
			next += now.substr(i + K);
			// �ߺ�üũ
			if (!visited.count(next)) {
				Q.push(pair<string, int>(next, cnt + 1));
				visited[next] = true;
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);
	
	string ST;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		ST += a;
	}

	cout << BFS(ST);

	return 0;
}