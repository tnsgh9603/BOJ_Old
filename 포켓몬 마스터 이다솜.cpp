#include <iostream>
#include <map>
#include <string>
using namespace std;
map <string, int> mp1;
map <int, string> mp2;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;
	string a;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		mp1.insert(pair<string, int>(a, i));
		mp2.insert(pair<int, string>(i, a));
	}
	for (int i = 0; i < M; i++) {
		cin >> a;
		if (mp1[a] == 0) {
			cout << mp2[stoi(a)] << "\n";
		}
		else {
			cout << mp1[a] << "\n";
		}
	}
	return 0;
}