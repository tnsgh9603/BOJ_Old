#include <iostream>
using namespace std;
int main() {
	int a, b=0, c;
	cin >> a;
	cin >> b;
	if (b >= 45) {
		c = 1;
	}
	if (b < 45) {
		c = 0;
	}
	if (c == 0 && a == 0) {
		a = 24;
	}
	switch (c) {
	case 1:
		cout << a <<" " <<  b - 45 << endl;
		break;
	case 0:
		cout << a - 1 <<" "<<  b + 15 << endl;
		break;
	}
	return 0;
}