#include <iostream>
using namespace std;
int main() {
	int arr[5];
	for (int i = 0; i <= 4; i++) {
		cin >> arr[i];
	}
	cout << (arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2] + arr[3] * arr[3] + arr[4] * arr[4] ) % 10;
	return 0;
}