#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[5001], palindrome[5001][5001];
int sol(int start, int end) {

	// Ż�� ����
	if (start > end) {
		return 0;
	}

	// �̹� Ž���ߴٸ� �ٷ� return
	if (palindrome[start][end] != -1) {
		return  palindrome[start][end];
	}

	// �Ӹ���Ҽ��� ������ �����Ѵٸ� ���� �ε��� Ž��
	if (arr[start] == arr[end]) {
		palindrome[start][end] = sol(start + 1, end - 1);
	}

	// ������ �������� �ʴٸ� ���� �ϳ��� �߰� �Ǿ�� �ϹǷ� + 1 ����
	// �׸��� start�ε����� end�ε��� �� �ϳ��� ������Ű�� ��͵�����
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