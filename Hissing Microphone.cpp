#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s; 
	cin >> s;
	regex r(R"(.*?ss.*?)");
	cout << (regex_match(s, r) ? "hiss" : "no hiss");
	return 0;
}