#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	cin >> s;
	char convert[16];
	convert[0] = '0';
	convert[1] = '1';
	convert[2] = '2';
	convert[3] = '3';
	convert[4] = '4';
	convert[5] = '5';
	convert[6] = '6';
	convert[7] = '7';
	convert[8] = '8';
	convert[9] = '9';
	convert[10] = 'A';
	convert[11] = 'B';
	convert[12] = 'C';
	convert[13] = 'D';
	convert[14] = 'E';
	convert[15] = 'F';
	unsigned int si;
	for (si = 0; si < s.size(); si++) {
		cout << convert[s[si] / 16] << convert[s[si] % 16];
	}
	return 0;
}