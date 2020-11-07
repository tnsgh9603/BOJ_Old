#include <iostream>
using namespace std;
int main() {
	int num1, num2;
	cin >> num1;
	cin >> num2;
	cout.precision(20);
	cout << (double)num1 / num2;
	return 0;
}