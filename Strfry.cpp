#include <iostream>
#include <memory.h>
using namespace std;
int arr1[26], arr2[26];
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		string s1, s2;
		cin >> s1 >> s2;
		bool flag = false;
		for (int i = 0; i < s1.length(); i++) {
			arr1[s1[i] - 'a']++;
		}
		for (int i = 0; i < s2.length(); i++) {
			arr2[s2[i] - 'a']++;
		}
		for (int i = 0; i <= 25; i++) {
			if (arr1[i] != arr2[i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "Impossible\n";
		}
		else {
			cout << "Possible\n";
		}

	}
}