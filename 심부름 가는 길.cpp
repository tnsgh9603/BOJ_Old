#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int sum = a + b + c + d;
	cout << sum / 60 << "\n" << sum % 60;
	return 0;
}