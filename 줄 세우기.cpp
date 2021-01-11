#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[32001];
vector <int> vec[32001];
queue <int> q;
int main() {
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[b]++; // arr에는 노드의 진입차수를 저장
		vec[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) { // 진입차수가 0인 것부터 큐에 push 해준다.
			q.push(i);
		}
	}
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		cout << i << " ";
		for (int j = 0; j < vec[i].size(); j++) {
			if (--arr[vec[i][j]] == 0) { // 간선 제거 후 진입차수가 0 이면 다시 큐에 넣어줌
				q.push(vec[i][j]);
			}
		}
	}
	return 0;
}