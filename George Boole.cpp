#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string a, b, c;
	cin >> a >> b >> c;
	int a1, c1;
	if (a == "true") {
		a1 = 1;
	}
	else {
		a1 = 0;
	}
	if (c == "true") {
		c1 = 1;
	}
	else {
		c1 = 0;
	}
	if (b == "AND") {
		a1 && c1 ? cout << "true" : cout << "false";
	}
	else {
		a1 || c1 ? cout << "true" : cout << "false";
	}
	return 0;
}