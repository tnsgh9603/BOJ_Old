#include <iostream>
using namespace std;
int main() {
	int n, m, num = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			cout << num++;
			if (k == m) {
				continue;
			}
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}