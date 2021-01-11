#include <iostream>
using namespace std;
int money[100001], N, M;
bool withdraw(int mid) {
	// cnt는 통장에서 돈을 뽑은 횟수
	int cnt = 1, sum = mid;
	for (int i = 0; i < N; i++)	{
		//인출하는 양이 하루 쓸 돈보다 적으면 모순
		if (mid < money[i]) {
			return false;
		}
		// 통장에서 돈을 뽑은 것이 오늘 써야하는 날보다 작다면
		if (sum - money[i] < 0) {
			// 돈을 뽑고 돈 뽑은 횟수 cnt++
			// 남은 금액을 다시 통장에 넣고 mid만큼 뺀다.
			sum = mid;
			cnt++;
		}
		// 오늘 써야하는 돈의 액수를 sum에서 차감
		sum -= money[i];
	}
	/* 만약 M이 cnt보다 크다면 mid값이 너무 큰 경우이고
	   M이 cnt와 같다면 더 최솟값을 찾아야하고
	   M이 cnt보다 작다면 mid값이 너무 작은 경우이다 */
	return M >= cnt;
}
int main() {
	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		sum += money[i];
	}
	int low = 1, high = sum, ans = 0, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (withdraw(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int INF = int(1e9);
int n, m;
vector<int> v;

bool check(int k) {
   int cnt = 0, cur = 0;
   for (int i = 0; i < n; i++) {
      if (cur < v[i]) cnt++, cur = k;
      if (cur < v[i]) return 0;
      cur -= v[i];
   }
   return cnt <= m;
}

int main() {
   fastio;
   cin >> n >> m;
   v.resize(n);
   for (int i = 0; i < n; i++) cin >> v[i];
   int lo = 0, hi = INF;
   while (lo + 1 < hi) {
      int mid = lo + hi >> 1;
      if (!check(mid)) lo = mid;
      else hi = mid;
   }
   cout << hi << '\n';
}
*/