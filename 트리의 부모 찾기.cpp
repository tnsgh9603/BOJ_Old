#include <iostream>
#include <vector>
using namespace std;

vector <int> tree[100001]; 
bool visited[100001]; // �湮���� ����
int arr[100001]; // �θ��带 �����ϴ� �迭

void dfs(int node) {
	visited[node] = true; //�湮�ߴٰ� �ٲ���
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i]; 
		if (!visited[next]) { //�湮���� �ʾҴٸ�
			arr[next] = node;
			dfs(next);
		}
	}
}

int main() {
	int node_number, from, to;
	cin >> node_number;
	tree->resize(node_number + 1);
	for (int i = 1; i < node_number; i++) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	dfs(1); // ��Ʈ����� 1�� �������� dfs����

	for (int i = 2; i <= node_number; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}