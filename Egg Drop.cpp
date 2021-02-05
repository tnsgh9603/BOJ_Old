#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, k, temp, minBrk, maxSafe;
	char state[12];
	cin >> n >> k;
	minBrk = k; maxSafe = 1;
	for (int i = 0; i < n; i++) {
		cin >> temp >> state;
		if (strcmp(state, "SAFE") == 0) {
			maxSafe = maxSafe < temp ? temp : maxSafe;
		}
		else {
			minBrk = minBrk < temp ? minBrk : temp;
		}
	}
	if (minBrk - maxSafe == 1) {
		cout << minBrk << " " << maxSafe << "\n";
	}
	else {
		cout << maxSafe + 1 << " " << minBrk - 1 << "\n";
	}
	return 0;
}