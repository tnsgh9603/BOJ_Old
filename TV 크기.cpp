#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	cout << int(sqrt(a * a / (b * b + c * c)) * b) << " " << int(sqrt(a * a / (b * b + c * c)) * c);
	return 0;
}