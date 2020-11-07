#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
vector <pair<int, int>> ans;
int main() {
	int C, N, input;
	cin >> C >> N;
	vec.resize(C);
	ans.resize(C);
	for (int i = 0; i < N; i++) {
		cin >> input;
		vec[input - 1]++;
	}
	for (int i = 0; i < vec.size(); i++) {
		ans[i] = make_pair(vec[i], i + 1);
	}
	sort(ans.begin(), ans.end(), greater<pair<int, int>>());
	cout << ans[2].second;
	return 0;
}