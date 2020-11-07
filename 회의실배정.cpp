#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> vec;
bool cmp(pair<int, int> a, pair <int, int> b) {
	if (a.second == b.second) { // ���� �ð��� ���ٸ� ���� �ð��� ���� ������ ����
		return a.first < b.first;
	}
	else {
		return a.second < b.second; // ���� �ð��� ���� ������ ����
	}
}
int main() {
	int N, start, end, n = 0, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		vec.emplace_back( start,end );
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size(); i++) {
		if (n <= vec[i].first) {
			n = vec[i].second;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}