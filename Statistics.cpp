#include <cstdio>
int main() {
	int t, n, ans = 0;
	scanf("%d %d", &t, &n);
	int temp = n;
	for (int i = 1; i < t; ++i) {
		scanf("%d", &n);
		if (n > temp) {
			ans += n - temp;
		}
		if (n < temp) {
			temp = n;
		}
	}
	printf("%d", ans);
	return 0;
}