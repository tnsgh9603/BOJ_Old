#include <iostream>
#include <cmath>
using namespace std;
void hanoi(int n, int first, int second, int third) {
	// first에 있는 n개의 원판을 third 원판을 이용해 second 원판으로 이동하겠다는 의미임
	if (n == 1) {
		cout << first << " " << third << "\n";
		// 첫 막대를 A, 중간 막대를 B, 마지막 막대를 C, 원판 개수를 N이라고 둔다.
		// A에 있는 원판 하나를 C로 옮긴다.
	}
	else {
		hanoi(n - 1, first, third, second);
		// A에 있는 원판 중 맨 마지막 원판을 제외한 N-1개의 막대들을 두 번째 막대에 모두 옮긴다.
		cout << first << " " << third << "\n";
		// A에 있는 원판 하나를 C로 옮긴다.
		hanoi(n - 1, second, first, third);
		// B에 옮겨 놧던 N-1개의 막대들을 다시 C로 옮겨준다.
	}
}
int main() {
	int input, a;
	cin >> input;
	a = pow(2, input) - 1;
	cout << a << "\n";
	hanoi(input, 1, 2, 3);
	cout << a;
	return 0;
}