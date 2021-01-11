#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a == 1 || (a == 2 && b <= 17)) {
		cout << "Before";
	}
	else if (a >= 3 || (a == 2 && b >= 19)) {
		cout << "After";
	}
	else {
		cout << "Special";
	}
	return 0;
}