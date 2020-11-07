#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, a;
	cin >> i;
	for (a = 1; a <= i; a++) {
		cout << a << "\n";
	}
	return 0;
}