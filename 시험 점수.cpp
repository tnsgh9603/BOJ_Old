#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	cout << max(a + b + c + d, e + f + g + h);
	return 0;
}