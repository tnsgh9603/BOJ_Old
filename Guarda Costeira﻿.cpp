#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int d, vf, vg;
	while (scanf("%d %d %d", &d, &vf, &vg) == 3) {
		printf("%c\n", (12 * 12 * vg * vg >= 12 * 12 * vf * vf + d * d * vf * vf) ? 'S' : 'N');
	}
	return 0;
}