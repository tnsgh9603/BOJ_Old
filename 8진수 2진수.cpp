#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            if (i == 0) {
                cout << '0';
            }
            else {
                cout << "000";
            }
        }
        else if (s[i] == '1') {
            if (i == 0) {
                cout << "1";
            }
            else {
                cout << "001";
            }
        }
        else if (s[i] == '2') {
            if (i == 0) {
                cout << "10";
            }
            else {
                cout << "010";
            }
        }
        else if (s[i] == '3') {
            if (i == 0) {
                cout << "11";
            }
            else {
                cout << "011";
            }
        }
        else if (s[i] == '4') {
            cout << "100";
        }
        else if (s[i] == '5') {
            cout << "101";
        }
        else if (s[i] == '6') {
            cout << "110";
        }
        else if (s[i] == '7') {
            cout << "111";
        }
    }
	return 0;
}