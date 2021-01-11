#include <iostream>
using namespace std;
int main() {
	int a, ans = 2, cnt1 = 2, cnt2 = 0;
	cin >> a;
	a -= 1;
	while (a--) {
		if (cnt2 < 2) {
			ans += cnt1;
			cnt2++;
		}
		else {
			cnt1++;
			ans += cnt1;
			cnt2 = 1;
		}
	}
	cout << ans;
}