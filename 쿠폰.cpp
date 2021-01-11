#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		double a;
		cin >> a;
		cout << fixed;
		cout.precision(2);
		cout << "$" << a * 0.8 << "\n";
	}
	return 0;
}