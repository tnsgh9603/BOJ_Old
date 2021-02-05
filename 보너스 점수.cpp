#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int score, bonus;
int main() {
	fastio;
	int n;
	char temp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		if (temp == 'O') {
			score += i + bonus;
			bonus++;
		}
		else {
			bonus = 0;
		}
	}
	cout << score;
	return 0;
}
