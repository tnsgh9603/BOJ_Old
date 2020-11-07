#include <iostream>
using namespace std;
int parent[100001];
int ans = 0;
int find(int x) {
	if (parent[x] == x) {
		return x; // ��Ʈ�� ã���� ��ȯ
	}
	return parent[x] = find(parent[x]); // ��Ʈ�� ��ã���� ã�������� ����Լ� �ݺ�
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}
int main() {
	int G, P, g_i;
	cin >> G >> P;
	
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= P; i++) {
		cin >> g_i;
		int docking = find(g_i);
		if (docking != 0) { 
			merge(docking, docking - 1);
            // ���������� find ȣ��� 0�� ������ �ȴٸ�, 
			// ��ŷ�� ����Ʈ�� ���ٴ� ��.
			ans++;
		}
		else {
			break;
		}
	}
	cout << ans;
	return 0;
}