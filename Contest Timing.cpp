#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c - 11 < 0) {
		b--;
		c += 60;
	}
	if (b - 11 < 0) {
		a--;
		b += 24;
	}
	int time = (a - 11) * 1440 + (b - 11) * 60 + c - 11;
	if (time < 0) {
		cout << -1;
	}
	else {
		cout << time;
	}
	return 0;
}