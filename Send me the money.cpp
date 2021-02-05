#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char arr[1005];
char brr[1005];
int main() {
	fastio;
	int N, M;
	cin >> M >> N >> arr;
	for (int i = 0; i < N; i++) {
		cin >> brr;
		int a = 0, b = 0;
		while (brr[b] != 0) {
			if (arr[a] == brr[b]) {
				a++;
			}
			b++;
		}
		puts(a == M ? "true" : "false");
	}
	return 0;
}