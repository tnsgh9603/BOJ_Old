#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e, time = 0;
	cin >> a >> b >> c >> d >> e;
	if (a < 0) {
		time += abs(a) * c;
		a = 0;
	}
	if (a == 0) {
		time += d;
	}
	if (b > 0) {
		time += (b - a) * e;
	}
	cout << time;
	return 0;
}