#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a >= b) {
		cout << "Congratulations, you are within the speed limit!";
	}
	else {
		int fine;
		if (b - a>=1 && b-a<=20) {
			fine = 100;
		}
		else if (b-a>=21 && b-a <=30) {
			fine = 270;
		}
		else {
			fine = 500;
		}
		cout << "You are speeding and your fine is $" << fine << ".";
	}
	return 0;
}