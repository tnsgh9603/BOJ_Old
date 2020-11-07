#include <iostream>
using namespace std;
int main() {
	int T, input;
	cin >> T;
	long long arr[101];
	arr[1] = 1;
	arr[2] = 1; 
	arr[3] = 1;
	for (int i = 4; i <= 100; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	for(int i = 1; i <= T; i++) {
		cin >> input;
		cout << arr[input] << "\n";
	}
	return 0;
}