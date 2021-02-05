#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int t, a, b;
char c[110];
int main() {
	scanf("%s %d", c, &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		if (a - b) {
			c[a] ^= c[b] ^= c[a] ^= c[b];
		}
	}
	printf("%s\n", c);
	return 0;
}