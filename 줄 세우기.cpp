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
		arr[b]++; // arr���� ����� ���������� ����
		vec[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) { // ���������� 0�� �ͺ��� ť�� push ���ش�.
			q.push(i);
		}
	}
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		cout << i << " ";
		for (int j = 0; j < vec[i].size(); j++) {
			if (--arr[vec[i][j]] == 0) { // ���� ���� �� ���������� 0 �̸� �ٽ� ť�� �־���
				q.push(vec[i][j]);
			}
		}
	}
	return 0;
}