#include <iostream>
using namespace std;
int arr[2][7];
int main() {
	int n, k, s, y, cnt = 0;
	cin >> n >> k;
	while (n--) {
		cin >> s >> y;
		arr[s][y]++;
	}
	for (int i = 0; i <= 1; i++) {
		for (int q = 0; q <= 6; q++) {
			if (arr[i][q] % k == 0) {
				cnt += arr[i][q] / k;
			}
			else {
				cnt += arr[i][q] / k + 1;
			}
		}
	}
	cout << cnt;
	return 0;
}