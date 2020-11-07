#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	for (int i = 1; i <= a * 2 - 1; i++) {
		if (i <= a) {
			for (int c = 1; c < i; c++) {
				cout << " ";
			}
			for (int b = 1; b <= (a - i + 1) * 2 - 1; b++) {
				cout << "*";
			}
		}
		if (i > a) {
			for (int c =2*a-i-1; c> 0; c--) {
				cout << " ";
			}
			for (int b = 1; b <=(i-a)*2 + 1; b++) {
				cout << "*";
			}
		}
		cout << endl;
	}
	return 0;
}