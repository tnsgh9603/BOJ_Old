#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int array2[12] = { 0, };
	char array[11] = { 0, };
	cin >> array;
	for (int i = 0; i <= strlen(array); i++) {
		array2[array[i]-'0']++;
	}
	for (int i = 10; i >= 0; i--) {
		if (array2[i] != 0) {
			for (int k = 1; k <= array2[i]; k++) {
				cout << i;
			}
		}
	}
	return 0;
}