#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, num = 0;
	char l;
	cin >> n >> l;
	for (int i = 0; i < n; ++i) {
		while (std::to_string(++num).find(l) != string::npos);
	}
	cout << num;
	return 0;
}