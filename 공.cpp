#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, a, b;
	cin >> n;
	int temp = 1;
	while (n--) {
		cin >> a >> b;
		if (a == temp) {
			temp = b;
		}
		else if (b == temp) {
			temp = a;
		}
	}
	cout << temp;
	return 0;
}