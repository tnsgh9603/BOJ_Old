#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<int, int> mp, order;
vector<pair<int, int>> vec;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return order[a.second] < order[b.second];
	}
	return a.first > b.first;
}
int main() {
	fastio;
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> b;
		mp[b]++;
		// ���� ����
		if (!order[b]) {
			order[b] = i;
		}
	}
	// mp�� �ִ��Ÿ� vec�� �Ű���
	for (auto i : mp) {
		vec.emplace_back(i.second, i.first);
	}
	sort(vec.begin(), vec.end(), compare);
	for (auto i : vec) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}
	return 0;
}