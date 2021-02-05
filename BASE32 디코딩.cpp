#include <bits/stdc++.h>
char a[90], b[410];
int main() {
	int i, j, n, k;
	scanf("%s", a);
	for (i = n = 0; a[i] && a[i] != '='; ++i) {
		k = a[i] < 65 ? a[i] - 24 : a[i] - 65;
		for (j = 5; j--;)b[++n] = !!(k & (1 << j));
	}
	for (i = 1; i + 6 < n;) {
		k = 0;
		for (j = 8; j--;)k = k * 2 + b[i++];
		printf("%c", k);
	}
	return 0;
}
