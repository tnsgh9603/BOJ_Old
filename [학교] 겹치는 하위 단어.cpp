#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;

	for (int k = 1; k <= n - 2; k++) {
		for (int j = k + 1; j <= n - k; j++) {
			for (int i = k; i <= n - j; i++) {
				cout << s.substr(i, j) << " " << s.substr(i - k, j) << "\n";
				if (s.substr(i, j) == s.substr(i - k, j)) {
					cout << "YES" << "\n";
					cout << s.substr(i, j);
					return 0;
				}
			}
		}
	}
	cout << "NO";
}