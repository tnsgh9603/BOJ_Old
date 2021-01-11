#include <iostream>
#include <map>
#include <string>
using namespace std;
map <string, string> mp;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;
	string a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		mp.insert(pair<string, string>(a, b));
	}
	for (int i = 0; i < M; i++) {
		cin >> c;
		cout << mp[c] << "\n";
	}
	return 0;
}