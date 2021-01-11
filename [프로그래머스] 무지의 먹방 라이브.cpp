#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> food_times, long long k) {
	long long cnt = 0, size = food_times.size(), q = 0, time = 0;
	while (cnt < size) {
		if (food_times[q] == 0) {

		}
		if (time == k) {
			while (food_times[q] == 0) {
				if (q >= size) {
					q -= size;
				}
				q++;
				if (q >= size) {
					q -= size;
				}
			}
			if (q >= size) {
				q -= size;
			}
			return q + 1;
		}
		if (food_times[q] == 1) {
			food_times[q]--;
			cnt++;
			time++;
		}
		else if (food_times[q] != 0) {
			food_times[q]--;
			time++;
		}
		q++;
		if (q >= size) {
			q -= size;
		}
	}
	return -1;
}
int main() {
	vector <int> food_times{ 100,100 };
	cout << solution(food_times, 11);
}
int solution2(vector<int> food_times, long long k) {
	long long sum = 0, previous = 0;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < food_times.size(); i++) {
		sum += food_times[i];
		// default가 mean heap이 아닌 max heap이므로 -를 붙여서 구현해줌
		// (걸리는 시간, 음식 번호)
		pq.push(make_pair(-food_times[i], (i + 1)));
	}
	// k가 모든 음식을 먹는데 걸리는 시간값 이상이면 어차피 더 먹을 음식이 없음
	if (sum <= k) {
		return -1;
	}
	// 우선순위 큐에서 시간이 가장 적게드는 요소를 하나씩 꺼내서 그 음식을 k시간안에 다 못먹을때까지 제거함
	while ((-pq.top().first - previous) * pq.size() <= k) {
		k -= (-pq.top().first - previous) * pq.size();
		previous = -pq.top().first;
		pq.pop();
	}
	vector<pair<int, int>> ans;
	// 이제 잔챙이들을 처리
	while (!pq.empty()) {
		ans.push_back(make_pair(pq.top().second, -pq.top().first));
		pq.pop();
	}
	sort(ans.begin(), ans.end());
	// 나머지 연산으로 마무리
	return ans[k % ans.size()].first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> input{ 1,22,3,74,5,56,27,2,1,2,3 };
	int k = 186;
	int ans1 = solution1(input, k),ans2= solution2(input, k);
	if (ans1 != ans2) {
		cout << ans1 << " " << ans2 << " 다름\n";
	}
	else {
		cout << "같음\n";
	}
}
