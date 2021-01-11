#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string, float> mp;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	double cnt = 0;

	while (getline(cin, s)) {
		cnt++;
		if (mp.find(s) != mp.end()) {
			mp[s] += 1;
		}
		else {
			mp[s] = 1;
		}
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << " " << it->second / cnt * 100 << "\n";
	}
	return 0;
}