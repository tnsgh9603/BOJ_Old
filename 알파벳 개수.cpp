#include <iostream>
#include <string>
using namespace std;
int arr[26];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 'a']++;
	}
	for (int i = 0; i <= 25; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}