#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[50];
int main() {
	fastio;
	int N, A, c, flag = 1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	if (N == 1) {
		cout << "A";
	}
	else if (N == 2) {
		if (arr[0] == arr[1]) {
			cout << arr[0];
		}
		else {
			cout << "A";
		}
	}
	else {
		int a = 0;
		if (arr[1] - arr[0] != 0) {
			a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
		}
		int b = arr[1] - arr[0] * a;
		for (int i = 1; i < N; i++) {
			if (arr[i] != arr[i - 1] * a + b) {
				cout << "B\n";
				return 0;
			}
		}
		cout << arr[N - 1] * a + b;
	}
	return 0;
}