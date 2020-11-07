#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	for (int i = 1; i <= a; i++) {
		cin >> c;
		if (c < b) {
			cout << c << " ";
		}
	}
	return 0;
}