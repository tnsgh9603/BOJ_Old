#include <iostream>
using namespace std;
int arr[1000001];
int main() {
	arr[1] = 1;
	arr[2] = 2;
	int input;
	cin >> input;
	for (int i = 3; i <= input; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] = arr[i] % 15746;
	}
	cout << arr[input];
	return 0;
}