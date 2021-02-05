#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int cnt[2], i;
char c;
int main() {
	fastio;
	while (scanf("%c", &c) != EOF) {
		if (c == '@') {
			cnt[i]++;
		}
		if (c == '(') {
			i++;
		}
	}
	cout << cnt[0] << " " << cnt[1];
	return 0;
}