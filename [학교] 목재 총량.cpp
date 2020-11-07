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