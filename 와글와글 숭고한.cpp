#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c >= 100) {
		cout << "OK";
	}
	else {
		if (a == min(a, min(b, c))) {
			cout << "Soongsil";
		}
		else if (b == min(a, min(b, c))) {
			cout << "Korea";
		}
		else {
			cout << "Hanyang";
		}
	}
	return 0;
}