#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[5001], palindrome[5001][5001];
int sol(int start, int end) {

	// 탈출 조건
	if (start > end) {
		return 0;
	}

	// 이미 탐색했다면 바로 return
	if (palindrome[start][end] != -1) {
		return  palindrome[start][end];
	}

	// 팰린드롬수의 성질을 만족한다면 다음 인덱스 탐색
	if (arr[start] == arr[end]) {
		palindrome[start][end] = sol(start + 1, end - 1);
	}

	// 성질을 만족하지 않다면 숫자 하나가 추가 되어야 하므로 + 1 해줌
	// 그리고 start인덱스와 end인덱스 중 하나만 증감시키고 재귀돌려줌
	else {
		palindrome[start][end] = min(1 + sol(start + 1, end), 1 + sol(start, end - 1));
	}

	return  palindrome[start][end];
}
int main() {

	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(palindrome, -1, sizeof(palindrome));

	cout << sol(0, n - 1);

	return 0;
}