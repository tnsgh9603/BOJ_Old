#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = (b / d) * (c / d);
	if (ans > a) {
		ans = a;
	}
	cout << ans;
}