#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t1, t2; 
	cin >> t1 >> t2;
	int ans = 2;
	while (t1 - t2 >= 0) {
		int tmp = t1 - t2;
		t1 = t2;
		t2 = tmp;
		ans++;
	} 
	cout << ans << "\n";
	return 0;
}