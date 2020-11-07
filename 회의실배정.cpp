#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> vec;
bool cmp(pair<int, int> a, pair <int, int> b) {
	if (a.second == b.second) { // 종료 시간이 같다면 시작 시간이 빠른 순으로 정렬
		return a.first < b.first;
	}
	else {
		return a.second < b.second; // 종료 시간이 빠른 순으로 정렬
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