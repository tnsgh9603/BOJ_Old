#include <iostream>
#include <string>
using namespace std;
int ans;
bool flag;
string tmp = "";
int main() {
	string sentence;
	cin >> sentence;
	for (int i = 0; i <= sentence.size(); i++) {
		if (sentence[i] == '+' || sentence[i] == '-' || sentence[i] == '\0') {
			if (flag) {
				ans -= stoi(tmp);
			}
			else {
				ans += stoi(tmp);
			}
			if (sentence[i] == '-') {
				flag = 1;
			}
			tmp = "";
			continue;
		}
		tmp += sentence[i];
	}
	cout << ans;
}