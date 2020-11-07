#include <iostream>
using namespace std;
int parent[100001];
int ans = 0;
int find(int x) {
	if (parent[x] == x) {
		return x; // 루트를 찾으면 반환
	}
	return parent[x] = find(parent[x]); // 루트를 못찾으면 찾을때까지 재귀함수 반복
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
            // 최종적으로 find 호출시 0이 나오게 된다면, 
			// 도킹할 게이트가 없다는 뜻.
			ans++;
		}
		else {
			break;
		}
	}
	cout << ans;
	return 0;
}