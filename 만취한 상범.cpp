#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
	fastio;
	int N;
	cin >> N;
	while (N--) { 
		int n;
		cin >> n;
		vector<bool> v(n); 
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				v[j - 1] = !v[j - 1];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += !v[i];
		}
		cout << cnt << '\n';
	}
	return 0;
}