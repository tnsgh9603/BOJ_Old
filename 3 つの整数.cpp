#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[3], cnt = 0;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			cnt++;
		}
	}
	if (cnt >= 2) {
		cout << 1;
	}
	else {
		cout << 2;
	}
}