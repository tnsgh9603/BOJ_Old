#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e,f,g;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	f = a;
	if (f > b) {
		f = b;
	}
	if (f > c) {
		f = c;
	}
	g = d;
	if (g > e) {
		g = e;
	}
	cout << f + g - 50;
	return 0;
}