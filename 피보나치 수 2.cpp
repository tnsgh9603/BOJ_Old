#include <iostream>
#include <vector>
using namespace std;
int main() {
	int input;
	cin >> input;
	vector <long long> arr(input + 1);

	for (int i = 0; i <= input; i++) {
		if (i == 0) {
			arr[i] = 0;
		}
		else if (i == 1) {
			arr[i] = 1;
		}
		else {
			arr[i] = arr[i-1] + arr[i-2];
		}
	}
	cout << arr[input];
	return 0;
}