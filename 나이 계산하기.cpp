#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e, f, ans1, ans2, ans3, flag = -1;
	cin >> a >> b >> c >> d >> e >> f;
	if (e > b || (e == b && f >= c)) {
		flag = 0;
	}
	ans1 = d - a + flag;
	ans2 = d - a + 1;
	ans3 = d - a;
	cout << ans1 << "\n" << ans2 << "\n" << ans3;
	return 0;
}