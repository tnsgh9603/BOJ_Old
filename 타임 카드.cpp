#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e, f, g;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b >> c >> d >> e >> f;
		if (f - c < 0) {
			e -= 1;
			f += 60;
		}
		if (e - b < 0) {
			d -= 1;
			e += 60;
		}
		cout << d - a << " " << e - b << " " << f - c << "\n";
	}
	return 0;
}