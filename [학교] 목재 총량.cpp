#include <iostream>
using namespace std;
int sum[1001][1001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> sum[i][j];
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1] << "\n";
	}
	return 0;
}

/*
#include <iostream>
using namespace std;
int arr[1001][1001];
int main() {
	int M, N;
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int k = 1; k <= N; k++) {
			cin >> arr[i][k];
		}
	}
	int num;
	int a, b, c, d;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		int sum = 0;
		cin >> a >> b >> c >> d;
		for (int i = a; i <= c; i++) {
			for (int k = b; k <= d; k++) {
				sum += arr[i][k];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
*/