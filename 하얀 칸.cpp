#include <iostream>
using namespace std;
char arr[8][8];
int cnt;
int main() {
	for (int i = 0; i <= 7; i++) {
		for (int k = 0; k <= 7; k++) {
			cin >> arr[i][k];
			if (arr[i][k] == 'F' && (i + k) % 2 == 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}