#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int input, testcase, answer[100000], cmp = 0, temp = 0, a;
	cin >> input;
	for (int i = 0; i < input; i++) {
		cin >> testcase;
		for (int j = 0; j < testcase; j++) {
			for (int k = 0; k < 3; k++) {
				cin >>a;
				if (a > cmp) {
					cmp = a;
				}
			}
			temp += cmp;
			cmp = 0;
		}
		answer[i] = temp;
		temp = 0;
	}
	for (int i = 0; i < input; i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}