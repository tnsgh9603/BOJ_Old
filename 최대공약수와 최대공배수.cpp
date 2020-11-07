#include <iostream>
using namespace std;
int main() {
	int a, b, tmp, min, max;
	cin >> a >> b;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	for (int i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			max = i;
		}
	}
	min = max * (a / max) * b / max;
	cout << max << "\n" << min;
	return 0;
}
/*
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	int a, b, tmp, min, max;
	cin >> a >> b;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	max = gcd(a,b);
	min = max * (a / max) * b / max;
	cout << max << "\n" << min;
	return 0;
}*/