#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	string d, e;
	cin >> d >> e;
	string sentence;
	cin >> sentence;
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == sentence[i + 1]) {
			sentence.erase(i + 1, 1);
			i--;
		}
	}
	if (sentence.find(d) == string::npos) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	if (sentence.find(e) == string::npos) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	return 0;
}