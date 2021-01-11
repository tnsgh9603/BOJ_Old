#include <iostream>
using namespace std;
int main() {
	int n, a, b, c;
	cin >> n;
	a = n / 300;
	n %= 300;
	b = n / 60;
	n %= 60;
	c = n / 10;
	n %= 10;
	if (n != 0) {
		cout << "-1";
	}
	else {
		cout << a << " " << b << " " << c;
	}
}