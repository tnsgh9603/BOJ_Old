#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool f(int a, int b, int c) {
	if (a < b) {
		swap(a, b);
	}
	if (a < c) {
		swap(a, c);
	}
	return a < b + c;
}

int main() {
	fastio;
	vector<int> v(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				cnt += f(v[i], v[j], v[k]);
			}
		}
	}
	cout << cnt;
	return 0;
}