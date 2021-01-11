#include <iostream>
using namespace std;
int main() {
	double a, b;
	cin >> a >> b;
	cout << fixed;
	cout.precision(6);
	cout << 2 * a + b * 2 * 3.141592;
	return 0;
}