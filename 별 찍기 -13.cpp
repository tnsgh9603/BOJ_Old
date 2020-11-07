#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	for (int i = 1; i <= a * 2 - 1; i++) {
		if (i <= a) {
			for (int b = 1; b <= i; b++) {
				cout << "*";
			}
		}
		if (i > a) {
			for (int c = a; c > i-a; c--) {
				cout << "*";
			}
		}
		cout << endl;
	}
	return 0;
}