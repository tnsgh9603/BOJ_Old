#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[9], sum;
int main() {
	fastio;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	do {
		for (int i = 0; i < 7; i++) {
			sum += arr[i];
		}
		if (sum == 100) {
			break;
		}
		sum = 0;
	} while (next_permutation(arr, arr + 9));
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}