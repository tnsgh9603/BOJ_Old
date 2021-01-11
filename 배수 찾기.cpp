#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N, value = 1;
	cin >> N;
	while (true) {
		cin >> value;
		if (value == 0) {
			break;
		}
		if (value % N == 0) {
			cout << value << " is a multiple of " << N << ".\n";
		}
		else {
			cout << value << " is NOT a multiple of " << N << ".\n";
		}
	}
}
