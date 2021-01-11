#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double n;
	cin >> n;
	cout << fixed;
	cout.precision(14);
	cout << n * n * sqrt(3) / 4;
	return 0;
}