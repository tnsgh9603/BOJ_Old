#include <iostream>
#include <vector>
using namespace std;

vector <int> tree[100001]; 
bool visited[100001]; // 방문여부 저장
int arr[100001]; // 부모노드를 저장하는 배열

void dfs(int node) {
	visited[node] = true; //방문했다고 바꿔줌
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i]; 
		if (!visited[next]) { //방문하지 않았다면
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

	dfs(1); // 루트노드인 1을 기준으로 dfs실행

	for (int i = 2; i <= node_number; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}