#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
char arr[1001][1001];
bool visited[1001][1001];
int M, N;
int ans[1];
void visit(int i, int k) {
	visited[i][k] = true;
	// »ó
	if (1 <= i - 1 && i - 1 <= M && 1 <= k && k <= N && arr[i - 1][k] == '.' && !visited[i - 1][k]) {
		visit(i - 1, k);
		ans[1]++;
	}
	// ÁÂ»ó
	if (1 <= i - 1 && i - 1 <= M && 1 < -k - 1 && k - 1 <= N && arr[i - 1][k - 1] == '.' && !visited[i - 1][k - 1]) {
		visit(i - 1, k - 1);
		ans[1]++;
	}
	// ÁÂ
	if (1 <= i && i <= M && k - 1 <= N && 1 <= k - 1 && arr[i][k - 1] == '.' && !visited[i][k - 1]) {
		visit(i, k - 1);
		ans[1]++;
	}
	// ÇÏ
	if (1 <= i + 1 && i + 1 <= M && k <= N && 1 <= k && arr[i + 1][k] == '.' && !visited[i + 1][k]) {
		visit(i + 1, k);
		ans[1]++;
	}
	// ¿ì
	if (1 <= i && i <= M && k + 1 <= N && 1 <= k + 1 && arr[i][k + 1] == '.' && !visited[i][k + 1]) {
		visit(i, k + 1);
		ans[1]++;
	}
	// ¿ìÇÏ
	if (1 <= i + 1 && i + 1 <= M && k + 1 <= N && 1 <= k + 1 && arr[i + 1][k + 1] == '.' && !visited[i + 1][k + 1]) {
		visit(i + 1, k + 1);
		ans[1]++;
	}
	// ÁÂÇÏ
	if (1 <= i + 1 && i + 1 <= M && k - 1 <= N && 1 <= k - 1 && arr[i + 1][k - 1] == '.' && !visited[i + 1][k - 1]) {
		visit(i + 1, k - 1);
		ans[1]++;
	}
	// ¿ì»ó
	if (1 <= i - 1 && i - 1 <= M && k + 1 <= N && 1 <= k + 1 && arr[i - 1][k + 1] == '.' && !visited[i - 1][k + 1]) {
		visit(i - 1, k + 1);
		ans[1]++;
	}
	return;
}
int main() {
	memset(visited, 0, sizeof(visited));
	int storm = 0;
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int k = 1; k <= N; k++) {
			cin >> arr[i][k];
		}
	}
	int K;
	int max_cnt = 0;
	cin >> K;
	for (int i = 1; i <= M; i++) {
		for (int k = 1; k <= N; k++) {
			if (!visited[i][k] && arr[i][k] == '.') {
				ans[1] = 1;
				visit(i, k);
				if (ans[1] > K) {
					storm++;
					max_cnt = max(max_cnt, ans[1]);
				}
			}
		}
	}
	cout << storm << " " << max_cnt;
	return 0;
}