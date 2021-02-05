#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
bool arr[31];
int main() {
	fastio;
	for (int i = 0; i < 28; i++) {
		int a;
		cin >> a;
		arr[a] = 1;
	}
	vector<int> v;
	for (int i = 1; i <= 30; i++) {
		if (!arr[i]) {
			v.push_back(i);
		}
	}
	cout << v.front() << '\n' << v.back();
	return 0;
}
