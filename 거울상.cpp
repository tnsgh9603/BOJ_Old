#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char S[11];
int i;
int main() {
	fastio;
	while (1) {
		cin >> S;
		if (*S == '#') {
			break;
		}
		for (i = 0; S[i]; i++) {
			if (S[i] == 'b') {
				S[i] = 'd';
			}
			else if (S[i] == 'd') {
				S[i] = 'b';
			}
			else if (S[i] == 'p') {
				S[i] = 'q';
			}
			else if (S[i] == 'q') {
				S[i] = 'p';
			}
			else if (S[i] != 'i' && S[i] != 'v' && S[i] != 'w' && S[i] != 'x' && S[i] != 'o') {
				break;
			}
		}
		if (S[i]) {
			cout << "INVALID\n";
		}
		else {
			reverse(S, S + i);
			cout << S << "\n";
		}
	}
	return 0;
}