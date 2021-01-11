#include <iostream>
using namespace std;
int main() {
	int a, b, cnt = 0;
	cin >> a;
	for (int i = 0; i < 5; i++) {
		cin >> b;
		if (b == a) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}