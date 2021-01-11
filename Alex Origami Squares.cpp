#include <iostream>
#include <vector>
using namespace std;
vector <double> vec;
int main() {
	double a, b;
	cin >> a >> b;
	if (a / 3 <= b) {
		vec.push_back(a / 3);
	}
	if (2 * (a / 2) <= b) {
		vec.push_back(a / 2);
	}
	if (b / 3 <= a) {
		vec.push_back(b / 3);
	}
	if (2 * (b / 2) <= a) {
		vec.push_back(b / 2);
	}
	if (3 * a <= b) {
		vec.push_back(a);
	}
	if (3 * b <= a) {
		vec.push_back(b);
	}
	cout << fixed;
	cout.precision(7);
	double ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (ans < vec[i]) {
			ans = vec[i];
		}
	}
	cout << ans;
	return 0;
}