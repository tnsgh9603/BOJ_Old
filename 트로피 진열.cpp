#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int trophy[50];
int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> trophy[i];
	}
	int left = 0, right = 0, left_max = -1, right_max = -1;
	for (int i = 0; i < n; i++)	{
		if (left_max < trophy[i]) {
			left_max = trophy[i];
			left++;
		}
		if (right_max < trophy[n - 1 - i]) {
			right_max = trophy[n - i - 1];
			right++;
		}
	}
	cout << left << "\n" << right;
	return 0;
}