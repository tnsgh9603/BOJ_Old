#include <iostream>
using namespace std;

// parent[a] = b -> a�� �θ�� b��
int parent[201];

int get_root(int parent[], int x) { // ��Ʈ�� ã�� ����
	
	if (parent[x] == x) { 
		return x; // ��Ʈ�� ã���� ��ȯ
	}
	return parent[x] = get_root(parent, parent[x]); // ��Ʈ�� ��ã���� ã�������� ����Լ� �ݺ�
}

void union_root(int parent[], int a, int b) {
	
	a = get_root(parent, a);
	b = get_root(parent, b);
	if (a == b) { // ��Ʈ�� ���� ������ �̹� ���� Ʈ����
		return;
	}
	else if (a < b) { // ������ �� ���ڰ� ���� ��带 �θ� ���� ����, �ݴ�� �ص� ����
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	
	int n, m, val;
	cin >> n >> m;

	// �ʱ⿡�� �ڽ��� �θ�� �ڱ� �ڽ�
	for (int i = 1; i <= n; i++){
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> val;

			if (j > i && val == 1) // val == 1 -> ����Ǿ� ������, ������ ������̶� j>i�� �ᵵ�ǰ� �Ƚᵵ ��
				union_root(parent, j,i);
		}
	}

	bool check = true;
	cin >> val;

	int u = get_root(parent,val); // ���� ��ȹ���� ���� �� ó�� ������ ��Ʈ ��带 �̸� �޾� ����
	for (int i = 0; i < m - 1; i++)
	{
		cin >> val; 
		// ���� ��ȹ���� �� ��° ���ú��� ó�� ������ ��Ʈ ����� ��
		// �ѹ��̶� ��Ʈ ��尡 �ٸ��� ���� �� ����� Ʈ���� �ƴ�

		if (u != get_root(parent,val)){ // ��Ʈ ��尡 ���� �ٸ��� ���� Ʈ���� �ƴ϶�� ��
			check = false; 
			break;
		}
	}

	check ? printf("YES") : printf("NO");
	//check�� true�� YES���, false�� NO���

	return 0;
}