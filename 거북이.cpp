#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> vec;
int main() {
	fastio;
	int num;
	for (int i = 0; i < 4; ++i) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	cout << vec[0] * vec[2];
	return 0;
}