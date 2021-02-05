#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N;
	while (cin >> N && N) {
		int arr[20], a = 0, b = 0;
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
		}
		for (int val, i = 0; i < N; ++i) {
			cin >> val;
			if (val == 1 && arr[i] == 2) {
				b += 6;
			}
			else if (val == 2 && arr[i] == 1) {
				a += 6;
			}
			else if (val + 1 == arr[i]) {
				b += val + arr[i];
			}
			else if (val == arr[i] + 1) {
				a += val + arr[i];
			}
			else if (val > arr[i]) {
				b += val;
			}
			else if (val < arr[i]) {
				a += arr[i];
			}
		}
		cout << "A has " << a << " points. B has " << b << " points.\n\n";
	}
	return 0;
}