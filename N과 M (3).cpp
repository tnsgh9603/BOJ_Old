#include <iostream>
using namespace std;
int n, m;
bool visited[9] = { 0, };
int list[9] = { 0, };
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		list[cnt] = i;
		dfs(cnt + 1);
	}
}
int main() {
	cin >> n >> m;
	dfs(0);
	return 0;
}