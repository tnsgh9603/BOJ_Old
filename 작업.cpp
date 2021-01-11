#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>
using namespace std;
int arr[10001], time[10001], total_time[10001];
queue <int> q;
vector<int> vec[10001];
int main() {
	int N, a, b, c, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		total_time[i] = time[i] = a;
		for (int k = 0; k < b; k++) {
			cin >> c;
			vec[c].push_back(i);
			arr[i]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			time[next] = max(time[next], total_time[next] + time[now]);
			if (--arr[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		ans = max(ans, time[i]);
	}
	cout << ans;
	return 0;
}