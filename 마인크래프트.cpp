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
			// 배열에다가 집어 넣고 높이의 최솟값과 최댓값을 따로 받아줌
			cin >> arr[i][k];
			if (input_max < arr[i][k]) {
				input_max = arr[i][k];
			}
			if (input_min > arr[i][k]) {
				input_min = arr[i][k];
			}
		}
	}
	int a = B; // 처음 인벤토리에 갖고 있던 블록 개수 저장
	// 높이의 최솟값부터 최댓값까지 탐색
	for (int i = input_min; i <= input_max; i++) {
		int sum1 = 0, sum2 = 0, count = 0, B = a;
		for (int m = 1; m <= M; m++) {
			for (int k = 1; k <= N; k++) {
				// 탐색하는 높이보다 해당 좌표의 높이가 더 큰 경우 블록을 제거한다. (한 블록당 2초)
				// 그리고 파준 블록을 인벤토리에 넣는다.
				if (arr[m][k] > i) {
					sum1 += (arr[m][k] - i) * 2;
					B += arr[m][k] - i;
				}
				// 탐색하는 높이보다 해당 좌표의 높이가 더 낮은 경우 블록을 그 좌표에 놓는다. (한 블록당 1초)
				// count는 블록을 놓은 개수를 저장한 변수다.
				if (arr[m][k] < i) {
					count += (i - arr[m][k]);
					sum2 += (i - arr[m][k]);
				}
			}
		}
		// 최소 시간이 같으면 높이가 높은 것이 출력 되도록 해야함
		if (ans == sum1 + sum2 && count <= B && height < i) {
			height = i;
		}
		// 총 블록을 놓은 개수가 인벤토리에 있는 개수보다 작거나 같아야 함.
		else if (ans > sum1 + sum2 && count <= B) {
			ans = sum1 + sum2;
			height = i;
		}
	}
	cout << ans << " " << height << "\n";
	return 0;
}