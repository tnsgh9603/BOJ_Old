#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int input, input2;
	cin >> input;
	int* array = new int[input];
	for (int i = 1; i <= input; i++) {
		cin >> input2;
		array[input2]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int k = 1; k <= array[i]; k++) {
			cout << i << "\n";
		}
	}
	return 0;
}