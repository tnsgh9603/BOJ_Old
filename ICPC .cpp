#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << (C + D) / (A - B);
	return 0;
}