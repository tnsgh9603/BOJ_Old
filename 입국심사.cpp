#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[100001];
int main() {
	// N : 입국심사대 수, M : 총 몇명
	int N, M;
	cin >> N >> M;
	ll val = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		// val에 심사하는데 가장 오래 걸리는 시간 저장
		val = max(val, arr[i]);
	}
	ll start = 1, end = val * M;
	while (start <= end) {
		ll mid = (start + end) >> 1, temp = 0;
		for (int i = 0; i < N; i++) {
			temp += mid / arr[i];
		}
		if (temp < M) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		cout << start << " " << end << "\n";
	}
	cout << start;
	return 0;
}