#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int x, y;
	x = a * e;
	if (e > c) {
		y = b + (e - c) * d;
	}
	else {
		y = b;
	}
	cout << min(x, y);
	return 0;
}