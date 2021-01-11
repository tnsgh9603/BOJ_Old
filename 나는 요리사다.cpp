#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[5][4];
int main() {
	fastio;
	int sum, max_ = 0, cook = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		sum = 0;
		for (int j = 0; j < 4; j++) {
			sum += arr[i][j];
		}
		if (sum > max_) {
			cook = i + 1;
			max_ = sum;
		}
	}
	cout << cook << ' ' << max_;
}