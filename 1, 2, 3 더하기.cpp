#include <iostream>
using namespace std;
int main() {
	int a[11], b, c;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for (int i = 4; i <= 10; i++) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	cin >> b;
	for (int i = 1; i <= b; i++) {
		cin >> c;
		cout << a[c] << "\n";
	}
	return 0;
}