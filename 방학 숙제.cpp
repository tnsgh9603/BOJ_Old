#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e, math, korean;
	cin >> a >> b >> c >> d >> e;
	if (b % d == 0) {
		math = b / d;
	}
	else {
		math = b / d + 1;
	}
	if (c % e == 0) {
		korean = c / e;
	}
	else {
		korean = c / e + 1;
	}
	cout << a - (max(math, korean));
	return 0;
}