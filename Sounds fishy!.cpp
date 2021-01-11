#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b - a > 0 && c - b > 0 && d - c > 0) {
		cout << "Fish Rising";
	}
	else if (a == b && b == c && c == d) {
		cout << "Fish At Constant Depth";
	}
	else if (b - a < 0 && c - b < 0 && d - c < 0) {
		cout << "Fish Diving";
	}
	else {
		cout << "No Fish";
	}
	return 0;
}