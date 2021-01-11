#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n[5];
	scanf("%d", &n[0]);
	for (int i = 1; n[0] != 0; i++) {
		n[1] = 3 * n[0];
		n[2] = (n[1] + 1) / 2;
		n[3] = 3 * n[2];
		n[4] = n[3] / 9;
		printf("%d. %s %d\n", i, n[1] % 2 == 0 ? "even" : "odd", n[4]);
		scanf("%d", &n[0]);
	}
	return 0;
}