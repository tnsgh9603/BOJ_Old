#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map <string, string> mp;
map <string, string>::reverse_iterator iter;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	string a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (b == "enter") {
			mp.insert(pair<string, string>(a, b));
		}
		else {
			mp.erase(a);
		}
	}
	for (iter = mp.rbegin(); iter != mp.rend(); iter++) {
		cout << iter->first << "\n";
	}
	return 0;
}