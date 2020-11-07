#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a == 1) {
		cout << "*";
	}
	else {
		for (int b = 1; b <= 2 * a; b++) {
			if (b % 2 == 1) {
				for (int c = 1; c <= a; c++) {
					if (c % 2 == 1) {
						cout << "*";
					}
					if (c % 2 == 0) {
						cout << " ";
					}
				}
			}
			if (b % 2 == 0) {
				for (int c = 1; c <= a; c++) {
					if (c % 2 == 0) {
						cout << "*";
					}
					if (c % 2 == 1) {
						cout << " ";
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}