#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
	fastio;
	string s1, s2;
	cin >> s1 >> s2;
	s1.size() >= s2.size() ? cout << "go" : cout << "no";
	return 0;
}
