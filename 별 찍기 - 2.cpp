#include <iostream>
using namespace std;
int main() {
	int i;
	cin >> i;
	for (int a = 1; a <= i; a++) {
		for (int b = 1; b < i-a+1; b++) {
			cout << " ";
		}
		for (int c = i-1; c >=i-a ; c--) {
			cout << "*";
		}
	cout << endl;
	}
	return 0;
}