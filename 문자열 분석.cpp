#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	while (getline(cin,s)) {
		int big_alphabet = 0, small_alphabet = 0, blank = 0, num = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				num++;
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				small_alphabet++;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				big_alphabet++;
			}
			else if (s[i] == ' ') {
				blank++;
			}
		}
		cout << small_alphabet << " " << big_alphabet << " " << num << " " << blank << "\n";
	}
}