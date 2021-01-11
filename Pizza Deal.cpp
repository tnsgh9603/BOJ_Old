#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;
int main() {
	double a, b, c, d, cnt1, cnt2;
	cin >> a >> b >> c >> d;
	cnt1 = a / b;
	cnt2 = c * c * M_PI / d;
	if (cnt1 > cnt2) {
		cout << "Slice of pizza";
	}
	else {
		cout << "Whole pizza";
	}
	return 0;
}