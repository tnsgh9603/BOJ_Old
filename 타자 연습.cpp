#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char L[] = "QWERTYASDFGZXCVBqwertyasdfgzxcvb", R[] = "UIOPHJKLNMuiophjklnm";
int l, r, c;
int main() {
	fastio;
	string S;
	getline(cin, S);
	for (int i = 0; S[i]; i++) {
		if (S[i] == ' ' || ('A' <= S[i] && S[i] <= 'Z')) {
			c++;
		}
		for (int j = 0; L[j]; j++) {
			if (L[j] == S[i]) {
				l++;
				break;
			}
		}
		for (int j = 0; R[j]; j++) {
			if (R[j] == S[i]) {
				r++;
				break;
			}
		}
	}
	for (int i = 0; i < c; i++) {
		if (l <= r) {
			l++;
		}
		else {
			r++;
		}
	}
	cout << l << " " << r;
	return 0;
}