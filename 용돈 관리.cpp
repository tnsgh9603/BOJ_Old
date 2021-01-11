#include <iostream>
using namespace std;
int money[100001], N, M;
bool withdraw(int mid) {
	// cnt�� ���忡�� ���� ���� Ƚ��
	int cnt = 1, sum = mid;
	for (int i = 0; i < N; i++)	{
		//�����ϴ� ���� �Ϸ� �� ������ ������ ���
		if (mid < money[i]) {
			return false;
		}
		// ���忡�� ���� ���� ���� ���� ����ϴ� ������ �۴ٸ�
		if (sum - money[i] < 0) {
			// ���� �̰� �� ���� Ƚ�� cnt++
			// ���� �ݾ��� �ٽ� ���忡 �ְ� mid��ŭ ����.
			sum = mid;
			cnt++;
		}
		// ���� ����ϴ� ���� �׼��� sum���� ����
		sum -= money[i];
	}
	/* ���� M�� cnt���� ũ�ٸ� mid���� �ʹ� ū ����̰�
	   M�� cnt�� ���ٸ� �� �ּڰ��� ã�ƾ��ϰ�
	   M�� cnt���� �۴ٸ� mid���� �ʹ� ���� ����̴� */
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