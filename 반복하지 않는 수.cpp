#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[1000001], cnt[10];
int main() {
	fastio;
	long long a = 1;
	for (int q = 1; q <= 1000000; q++) {
		string s = to_string(a);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.length(); i++) {
			cnt[s[i] - '0']++;
		}
		bool flag = 1;
		for (int i = 0; i <= 9; i++) {
			if (cnt[i] >= 2) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			arr[q] = a;
		}
		else {
			q--;
		}
		a++;
		cout << a << "\n";
	}
	int n;
	while (cin >> n && n) {
		cout << arr[n] << "\n";
	}
	return 0;
}