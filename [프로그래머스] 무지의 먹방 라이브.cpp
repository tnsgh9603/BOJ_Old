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
		// default�� mean heap�� �ƴ� max heap�̹Ƿ� -�� �ٿ��� ��������
		// (�ɸ��� �ð�, ���� ��ȣ)
		pq.push(make_pair(-food_times[i], (i + 1)));
	}
	// k�� ��� ������ �Դµ� �ɸ��� �ð��� �̻��̸� ������ �� ���� ������ ����
	if (sum <= k) {
		return -1;
	}
	// �켱���� ť���� �ð��� ���� ���Ե�� ��Ҹ� �ϳ��� ������ �� ������ k�ð��ȿ� �� ������������ ������
	while ((-pq.top().first - previous) * pq.size() <= k) {
		k -= (-pq.top().first - previous) * pq.size();
		previous = -pq.top().first;
		pq.pop();
	}
	vector<pair<int, int>> ans;
	// ���� ��ì�̵��� ó��
	while (!pq.empty()) {
		ans.push_back(make_pair(pq.top().second, -pq.top().first));
		pq.pop();
	}
	sort(ans.begin(), ans.end());
	// ������ �������� ������
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
		cout << ans1 << " " << ans2 << " �ٸ�\n";
	}
	else {
		cout << "����\n";
	}
}
