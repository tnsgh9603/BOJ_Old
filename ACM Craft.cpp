#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
vector <int> vec[1001];
int time[1001], arr[1001], total_time[1001];
queue <int> q;
int main() {
	int T, N, K, W, X, Y;
	cin >> T;
	for (int z= 1; z <= T; z++) {
		for (int i = 0; i <= 1000; i++) {
			vec[i].clear();
		}
		memset(time, 0, sizeof(time));
		memset(arr, 0, sizeof(arr));
		memset(total_time, 0, sizeof(total_time));
		while (!q.empty()) {
			q.pop();
		}
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> time[i];
		}
		for (int i = 1; i <= K; i++) {
			cin >> X >> Y;
			vec[X].push_back(Y);
			arr[Y]++;
		}
		cin >> W;
		for (int i = 1; i <= N ; i++) {
			if (arr[i] == 0) {
				q.push(i);
				total_time[i] = time[i];
			}
		}
		// bfs
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			// 마지막 건물을 건설했으면 종료
			if (now == W) {
				break;
			}
			for (int i = 0; i < vec[now].size(); i++) {
				int next = vec[now][i];
				if (--arr[next] == 0) {
					q.push(next);
				}
				// 비용시간이 더 큰게 있으면 갱신
				if (total_time[next] < total_time[now] + time[next]) {
					total_time[next] = total_time[now] + time[next];
				}
			}
		}
		cout << total_time[W] << '\n';
	}
}