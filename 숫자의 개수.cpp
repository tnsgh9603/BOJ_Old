#include <iostream>
using namespace std;
int main() {
	int first, second, third, product, count = 1, a ,a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;
	cin >> first;
	cin >> second;
	cin >> third;
	product = first * second * third * 10;
	for (; product > 0;) {
		product /= 10;
		if (product == 0) {
			break;
		}
		a = product % 10;
		if (a == 0) {
			a0++;
		}
		if (a == 1) {
			a1++;
		}
		if (a == 2) {
			a2++;
		}
		if (a == 3) {
			a3++;
		}
		if (a == 4) {
			a4++;
		}
		if (a == 5) {
			a5++;
		}
		if (a == 6) {
			a6++;
		}
		if (a == 7) {
			a7++;
		}
		if (a == 8) {
			a8++;
		}
		if (a == 9) {
			a9++;
		}
	}
	cout << a0 << endl << a1 << endl << a2 << endl << a3 << endl << a4 << endl << a5 << endl << a6 << endl << a7 << endl << a8 << endl << a9;
	return 0;
}