#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, S, T;
	cin >> N;
	int left = 0, right = 0, sum_left = 0, sum_right = 0;
	for (int i = 1; i <= N; i++) {
		cin >> S >> T;
		sum_left += S;
		sum_right += T;
		if (sum_left > sum_right) {
			left = max(left, sum_left - sum_right);
		}
		else {
			right = max(right, sum_right - sum_left);
		}
	}
	if (left > right) {
		cout << "1 " << left;
	}
	else {
		cout << "2 " << right;
	}
	return 0;
}