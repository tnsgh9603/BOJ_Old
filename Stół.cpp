#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a / c) * (b / c) - max(0, a / c - 2) * max(0, b / c - 2);
	//cout << 2 * (a / c + b / c) - 4;
	return 0;
}