#include <bits/stdc++.h>
using namespace std;
int main() {
	double a, b, rate, time = 0;
	cin >> a >> b;
	if (b >= 20) {
		rate = (100 - b) / a;
		time += (b - 20) / rate;
		time += (20 * 2) / rate;
	}
	else {
		rate = (120 - 2 * b) / a;
		time = (b * 2) / rate;
	}
	cout << fixed << setprecision(4) << time;
	return 0;
}