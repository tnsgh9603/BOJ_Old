#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(b * 2 + 4 * c, min(2 * (a + c), 4 * a + 2 * b));
	return 0;
}