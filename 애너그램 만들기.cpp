#include <iostream>
#include <algorithm>
using namespace std;
int arr1[26], arr2[26];
int main() {
	int cnt = 0;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		arr1[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.length(); i++) {
		arr2[s2[i] - 'a']++;
	}
	for (int i = 0; i <= 25; i++) {
		cnt += min(arr1[i], arr2[i]);
	}
	cout << s1.length() + s2.length() - 2 * cnt;
	return 0;
}