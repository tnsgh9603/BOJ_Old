#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c;
	cin >> a >> b >> c;
	vector<int>vec{ a,b,c };
	sort(vec.begin(), vec.end());
	int sum = vec[0] + vec[1];
	int temp = min(sum - 1, vec[2]);
	cout << sum + temp;
	return 0;
}