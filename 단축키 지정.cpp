#include <iostream>
#include <string>
using namespace std;
int arr[26];
int main() {
	int n;
	string s;
	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin, s);
		string s2 = "";
		bool flag = false;
		// 앞글자부터 탐색
		for (int i = 0; i < s.length(); i++) {
			if (i == 0 || (i >= 1 && s[i - 1] == ' ')) {
				if (s[i] != ' ' && arr[tolower(s[i]) - 'a'] == 0) {
					for (int k = 0; k < i; k++) {
						s2 += s[k];
					}
					s2 += "[" + s.substr(i, 1) + "]";
					for (int k = i + 1; k < s.length(); k++) {
						s2 += s[k];
					}
					flag = true;
					arr[tolower(s[i]) - 'a']++;
					cout << s2 << "\n";
					break;
				}
			}
		}
		// 앞글자를 모두 탐색해도 못 찾은경우
		if (!flag) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] != ' ' && arr[tolower(s[i]) - 'a'] == 0) {
					arr[tolower(s[i]) - 'a']++;
					for (int k = 0; k < i; k++) {
						s2 += s[k];
					}
					s2 += "[" + s.substr(i, 1) + "]";
					for (int k = i + 1; k < s.length(); k++) {
						s2 += s[k];
					}
					flag = true;
					cout << s2 << "\n";
					break;
				}
			}
		}
		// 단축키 지정이 불가한 경우
		if (!flag) {
			cout << s << "\n";
		}
	}
	return 0;
}