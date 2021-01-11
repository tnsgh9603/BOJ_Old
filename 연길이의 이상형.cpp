#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s1,s2;
	cin >> s1;
	if (s1[0] == 'E') {
		s2 += 'I';
	}
	else {
		s2 += 'E';
	}
	if (s1[1] == 'S') {
		s2 += 'N';
	}
	else {
		s2 += 'S';
	}
	if (s1[2] == 'T') {
		s2 += 'F';
	}
	else {
		s2 += 'T';
	}
	if (s1[3] == 'J') {
		s2 += 'P';
	}
	else {
		s2 += 'J';
	}
	cout << s2;
	return 0;
}