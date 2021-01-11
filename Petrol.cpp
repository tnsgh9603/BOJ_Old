#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a - b >= 60) {
		cout << (a - b - 60) * 3000;
	}
	else {
		cout << a * 1500;
	}
	return 0;
}