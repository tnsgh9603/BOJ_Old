#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	while (1) {
		vector<int> A(6);
		for (auto& Ai : A) cin >> Ai;
		if (accumulate(A.begin(), A.end(), 0) == 0) {
			break;
		}
		sort(A.begin(), A.end());
		A.erase(A.begin());
		A.erase(A.end() - 1);
		cout << ((double)accumulate(A.begin(), A.end(), 0)) / 4 << '\n';
	}
	return 0;
}