#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	cin >> s;
	unsigned int si;
	int convert[128];
	convert['1'] = 1;
	convert['2'] = 2;
	convert['3'] = 3;
	convert['4'] = 4;
	convert['5'] = 5;
	convert['6'] = 6;
	convert['7'] = 7;
	convert['8'] = 8;
	convert['9'] = 9;
	convert['0'] = 0;
	convert['A'] = 10;
	convert['B'] = 11;
	convert['C'] = 12;
	convert['D'] = 13;
	convert['E'] = 14;
	convert['F'] = 15;
	for (si = 0; si < s.size(); si += 2) {
		cout << (char)(convert[s[si]] * 16 + convert[s[si + 1]]);
	}
	return 0;
}