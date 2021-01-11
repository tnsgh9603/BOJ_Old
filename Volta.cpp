#include <bits/stdc++.h>
using namespace std;
int main() {
	double a, b;
	cin >> a >> b;
	cout << ceil(1 / abs(1 / a - 1 / b) * 1 / min(a, b));
	return 0;
}