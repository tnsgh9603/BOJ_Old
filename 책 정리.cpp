#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, m, sumA = 0, sumB = 0, arrA[50], arrB[50];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
		sumA += arrA[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arrB[i];
		sumB += arrB[i];
	}
	cout << sumA - sumB;
	return 0;
}