#include <iostream>
using namespace std;
int main() {
	int N;
	long long int arr[100001];
	long long int Liquid_A, Liquid_B;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0; // 맨 왼쪽
	int right = N - 1; // 맨 오른쪽

	// 임의로 설정
	int resLiquid = abs(arr[left] + arr[right]); 
	Liquid_A = arr[left];
	Liquid_B = arr[right];

	// 중앙으로 모아주며 반복
	while (left < right) {
		int tmp_Liquid = arr[left] + arr[right];
		if (abs(tmp_Liquid) < resLiquid) {
			resLiquid = abs(tmp_Liquid);
			Liquid_A = arr[left];
			Liquid_B = arr[right];
		}

		if (tmp_Liquid < 0) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << Liquid_A << " " << Liquid_B << "\n";
}