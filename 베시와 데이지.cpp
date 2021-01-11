#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e, f, bessie = 0, daisy = 0;
	cin >> a >> b >> c >> d >> e >> f;
	bessie = max(abs(a - e), abs(b - f));
	daisy = abs(c - e) + abs(d - f);
	if (bessie < daisy) {
		cout << "bessie";
	}
	else if (bessie == daisy) {
		cout << "tie";
	}
	else {
		cout << "daisy";
	}
	return 0;
}