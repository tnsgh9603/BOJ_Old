#include <iostream>
using namespace std;

// parent[a] = b -> a의 부모는 b다
int parent[201];

int get_root(int parent[], int x) { // 루트를 찾아 떠남
	
	if (parent[x] == x) { 
		return x; // 루트를 찾으면 반환
	}
	return parent[x] = get_root(parent, parent[x]); // 루트를 못찾으면 찾을때까지 재귀함수 반복
}

void union_root(int parent[], int a, int b) {
	
	a = get_root(parent, a);
	b = get_root(parent, b);
	if (a == b) { // 루트가 서로 같으면 이미 같은 트리임
		return;
	}
	else if (a < b) { // 연결할 때 숫자가 작은 노드를 부모 노드로 설정, 반대로 해도 무관
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	
	int n, m, val;
	cin >> n >> m;

	// 초기에는 자신의 부모는 자기 자신
	for (int i = 1; i <= n; i++){
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> val;

			if (j > i && val == 1) // val == 1 -> 연결되어 있을때, 어차피 양방향이라 j>i를 써도되고 안써도 됨
				union_root(parent, j,i);
		}
	}

	bool check = true;
	cin >> val;

	int u = get_root(parent,val); // 여행 계획중인 도시 중 처음 도시의 루트 노드를 미리 받아 놓음
	for (int i = 0; i < m - 1; i++)
	{
		cin >> val; 
		// 여행 계획중인 두 번째 도시부터 처음 도시의 루트 노드들과 비교
		// 한번이라도 루트 노드가 다르면 서로 다 연결된 트리가 아님

		if (u != get_root(parent,val)){ // 루트 노드가 서로 다르면 같은 트리가 아니라는 말
			check = false; 
			break;
		}
	}

	check ? printf("YES") : printf("NO");
	//check가 true면 YES출력, false면 NO출력

	return 0;
}