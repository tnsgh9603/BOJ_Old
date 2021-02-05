#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[50], temp[50], temp2[50];
int main() {
	int N, i;
	fastio;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (i = 0; i < N; i++) {
		temp[i] = arr[i + 1] - arr[i];
		temp2[i] = arr[i + 1] / arr[i];
	}
	for (i = 0; i < N; i++) {
		if (temp[i] == temp[i + 1]) {		
			cout << arr[N - 1] + temp[0] << "\n";
			break;
		}
		if (temp2[i] == temp2[i + 1]) {
			cout << arr[N - 1] * temp2[0] << "\n";
			break;
		}
	}
	return 0;
}
