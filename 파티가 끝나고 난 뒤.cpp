#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b;
	int mul = a * b;
	for (int i = 0; i < 5; i++) {
		cin >> c;
		cout << c - mul << " ";
	}
}