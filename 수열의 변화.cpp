#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int num[21];
int main() { 
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) { 
		scanf("%d,", &num[i]); 
	}
	for (int i = 0; i < k; i++, n--) {
		for (int j = 0; j < n - 1; j++) { 
			num[j] = num[j + 1] - num[j]; 
		} 
	}
	for (int i = 0; i < n - 1; i++) {
		cout << num[i] << ",";
	}
	cout << num[n - 1];
	return 0;
}