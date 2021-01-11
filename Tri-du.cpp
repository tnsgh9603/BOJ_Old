#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << a;
	}
	else {
		cout << max(a, b);
	}
	return 0;
}