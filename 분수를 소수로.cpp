#include <iostream>
#include <memory.h>
using namespace std;
int arr[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, k = 0, start = 0, finish = 0, temp;
		memset(arr, -1, sizeof(arr));

		cin >> a >> b;

		//몫부터 출력
		cout << a / b << ".";

		temp = a % b * 10;

		//순환되는 부분까지 찾기
		while (1) {
			a = a % b * 10;
			if (arr[a] != -1) {
				start = arr[a];
				finish = k;
				break;
			}
			arr[a] = k++;
		}
		// 순환되는 부분 전에 부분 출력
		for (int i = 0; i < start; i++) {
			cout << temp / b;
			temp = temp % b * 10;
		}
		cout << "(";
		// 순환되는 부분 출력
		for (int i = start; i < finish; i++) {
			cout << temp / b;
			temp = temp % b * 10;
		}
		cout << ")\n";
	}
	return 0;
}