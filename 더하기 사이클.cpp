#include <iostream>
int main() {
	int a, b, c, d = 0, e = 0, f, g;
	std::cin >> a;
	if (a < 10) {
		a *= 10;
	}
	g = a;
	while(1){
		b = a / 10;
		c = a % 10;
		f = b + c;
		if (b + c >= 10) {
			f = f - 10;
		}
		a = c * 10 + f;
		e++;
		if (a == g) {
			break;
		}
	}
	std:: cout << e;
	return 0;
}