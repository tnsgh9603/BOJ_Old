#include <iostream>
using namespace std;
int main() {
	int input1, input2;
	cin >> input1;
	for (int i = 1; i <= input1; i++) {
		cin >> input2;
		int arr[41][2] = { 0, };
		for (int k = 0; k <= input2; k++) {
			if (k == 0) {
				arr[k][0] = 1;
				arr[k][1] = 0;
			}
			else if (k == 1) {
				arr[k][0] = 0;
				arr[k][1] = 1;
			}
			else {
				arr[k][0] = arr[k - 1][0] + arr[k - 2][0];
				arr[k][1] = arr[k - 1][1] + arr[k - 2][1];
			}
		}
		cout << arr[input2][0] << " " << arr[input2][1] << "\n";
	}
	return 0;
}