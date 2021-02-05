#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			if (i % 111 == 0 && j % 111 == 0) {
				continue;
			}
			if (i * (j % 100) == (i / 10) * j && i % 10 == j / 100) {
				cout << i << " / " << j << " = " << i / 10 << " / " << j % 100 << '\n';
			}
		}
	}
	return 0;
}