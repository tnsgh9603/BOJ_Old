#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((b - a) % c != 0) {
		cout << (b - a) / c + 1;
	}
	else {
		cout << (b - a) / c;
	}
	return 0;
}