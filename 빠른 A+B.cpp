#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, a, b, c;
	cin >> i;
	for (a = 1; a <= i; a++) {
		cin >> b;
		cin >> c;
		cout << b + c << "\n";
	}
	return 0;
}