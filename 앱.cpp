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
	// cost[i] �ȿ� ��� �ִ� ���� i��° ���� ��Ȱ��ȭ�ϴµ� ��� ���
	// memory[i] �ȿ� ��� �ִ� ���� i��° ���� Ȱ��ȭ �ϴµ� ��� �޸�
	// dp[i] �ȿ� ��� �ִ� ���� ��� i�� Ȯ���� �� �ִ� �ִ� �޸�
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