#include <iostream>
using namespace std;
int cost[1001][3], arr[3];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[0] >> arr[1] >> arr[2];
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + arr[0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + arr[1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + arr[2];
	}
	cout << min(cost[n][0], min(cost[n][1], cost[n][2]));
	return 0;
}