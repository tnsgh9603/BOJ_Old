#include <iostream>
#include <map>
using namespace std;
map <int, int> mp;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> a;
		if (mp.count(a)) {
			mp.erase(a);
		}
		else {
			mp.insert(pair<int, int>(a, 1));
		}
	}
	cout << mp.size();
	return 0;
}