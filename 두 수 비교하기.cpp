#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a;
	cin >> b;
	if (a == b) {
		cout << "==";
	}
	if (a > b) {
		cout << ">";
	}
	if (a < b) {
		cout << "<";
	}
	return 0;
}