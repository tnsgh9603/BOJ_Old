#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int arr[501][501];
int main() {
	int M, N, B, input_max = -1, input_min = INT_MAX, ans = INT_MAX, height = -1;
	cin >> M >> N >> B;
	for (int i = 1; i <= M; i++) {
		for (int k = 1; k <= N; k++) {
			// �迭���ٰ� ���� �ְ� ������ �ּڰ��� �ִ��� ���� �޾���
			cin >> arr[i][k];
			if (input_max < arr[i][k]) {
				input_max = arr[i][k];
			}
			if (input_min > arr[i][k]) {
				input_min = arr[i][k];
			}
		}
	}
	int a = B; // ó�� �κ��丮�� ���� �ִ� ��� ���� ����
	// ������ �ּڰ����� �ִ񰪱��� Ž��
	for (int i = input_min; i <= input_max; i++) {
		int sum1 = 0, sum2 = 0, count = 0, B = a;
		for (int m = 1; m <= M; m++) {
			for (int k = 1; k <= N; k++) {
				// Ž���ϴ� ���̺��� �ش� ��ǥ�� ���̰� �� ū ��� ����� �����Ѵ�. (�� ��ϴ� 2��)
				// �׸��� ���� ����� �κ��丮�� �ִ´�.
				if (arr[m][k] > i) {
					sum1 += (arr[m][k] - i) * 2;
					B += arr[m][k] - i;
				}
				// Ž���ϴ� ���̺��� �ش� ��ǥ�� ���̰� �� ���� ��� ����� �� ��ǥ�� ���´�. (�� ��ϴ� 1��)
				// count�� ����� ���� ������ ������ ������.
				if (arr[m][k] < i) {
					count += (i - arr[m][k]);
					sum2 += (i - arr[m][k]);
				}
			}
		}
		// �ּ� �ð��� ������ ���̰� ���� ���� ��� �ǵ��� �ؾ���
		if (ans == sum1 + sum2 && count <= B && height < i) {
			height = i;
		}
		// �� ����� ���� ������ �κ��丮�� �ִ� �������� �۰ų� ���ƾ� ��.
		else if (ans > sum1 + sum2 && count <= B) {
			ans = sum1 + sum2;
			height = i;
		}
	}
	cout << ans << " " << height << "\n";
	return 0;
}