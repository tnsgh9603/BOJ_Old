#include <iostream>
using namespace std;
int main() {
	int i, a, c = 0;
	cin >> i;
	for (a = 1; a <= i; a++) {
		c = c + a;
	}
	cout << c;
	return 0;
}