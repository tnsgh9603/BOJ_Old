#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, i, j, squ[3], max = 0, sum = 0, maxj;
	cin >> n;
	for (i = 0; i < n; i++) {
		max = 0;
		sum = 0;
		for (j = 0; j < 3; j++) {
			cin >> squ[j];
			if (squ[j] > max) {
				max = squ[j];
				maxj = j;
			}
		}
		for (j = 0; j < 3; j++) {
			if (j != maxj) {
				sum += (squ[j] * squ[j]);
			}
		}
		printf("Scenario #%d:\n", i + 1);
		if (sum == (squ[maxj] * squ[maxj])) {
			printf("yes\n\n");
		}
		else {
			printf("no\n\n");
		}
	}
}