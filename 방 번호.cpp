#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[10];
int main() {
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] - '0' == 9) {
			arr[6]++;
			continue;
		}
		arr[s[i] - '0']++;
	}
	for (int i = 0; i <= 8; i++) {
		if (i == 6) {
			if (arr[i] % 2 == 0) {
				cnt = max(cnt, arr[i] / 2);
			}
			else {
				cnt = max(cnt, arr[i] / 2 + 1);
 			}
			continue;
		}
		cnt = max(cnt, arr[i]);
	}
	cout << cnt;
	return 0;
}