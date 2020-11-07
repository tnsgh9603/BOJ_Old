#include <iostream>
using namespace std;
int main() {
	int i, b;
	cin >> i;
	for (int a = 1; a <= i; a++) {
		for (b=1; b <= a; b++) {
			cout << "*";
		}
		cout << endl;
	}
}