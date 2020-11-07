#include <iostream>
#include <algorithm>
using namespace std;
int memory[101];
int cost[101];
int dp[10001];
int main() {
	int n, m, sum = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> memory[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}
	// cost[i] 안에 들어 있는 값은 i번째 앱을 비활성화하는데 드는 비용
	// memory[i] 안에 들어 있는 값은 i번째 앱을 활성화 하는데 드는 메모리
	// dp[i] 안에 들어 있는 값은 비용 i로 확보할 수 있는 최대 메모리
	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}
	}
	int i = 0;
	while (i < sum && dp[i] < m) {
		i++;
	}
	cout << i;
	return 0;
}