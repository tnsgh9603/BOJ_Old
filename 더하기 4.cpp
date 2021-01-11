#include <iostream>
#include <sstream>
using namespace std;
int main() {
	int n; 
	cin >> n;
	cin.ignore();
	while (n--) {
		string s; 
		getline(cin, s);
		stringstream in(s);
		int sum = 0, t;
		while (in >> t) {
			sum += t;
		}
		cout << sum << '\n';
	}
}