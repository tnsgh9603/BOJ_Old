#include <iostream>
using namespace std;
int main() {
	int arr[8];
	for (int i = 0; i <= 7; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= 6; i++) {
		if (!(arr[i + 1] - arr[i] == 1 || arr[i + 1] - arr[i] == -1)) {
			cout << "mixed";
			return 0;
		}
	}
	if (arr[3] - arr[2] == 1) {
		cout << "ascending";
	}
	if (arr[3] - arr[2] == -1) {
		cout << "descending";
	}
	return 0;
}