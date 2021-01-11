#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a += d / 3600;
	d %= 3600;
	b += d / 60;
	d %= 60;
	c += d;
	if (c >= 60) {
		c %= 60;
		b += 1;
	}
	if (b >= 60) {
		b %= 60;
		a += 1;
	}
	if (a >= 24) {
		a %= 24;
	}
	cout << a << " " << b << " " << c;
	return 0;
}