#include <iostream>
#include <cmath>
using namespace std;
void hanoi(int n, int first, int second, int third) {
	// first�� �ִ� n���� ������ third ������ �̿��� second �������� �̵��ϰڴٴ� �ǹ���
	if (n == 1) {
		cout << first << " " << third << "\n";
		// ù ���븦 A, �߰� ���븦 B, ������ ���븦 C, ���� ������ N�̶�� �д�.
		// A�� �ִ� ���� �ϳ��� C�� �ű��.
	}
	else {
		hanoi(n - 1, first, third, second);
		// A�� �ִ� ���� �� �� ������ ������ ������ N-1���� ������� �� ��° ���뿡 ��� �ű��.
		cout << first << " " << third << "\n";
		// A�� �ִ� ���� �ϳ��� C�� �ű��.
		hanoi(n - 1, second, first, third);
		// B�� �Ű� �J�� N-1���� ������� �ٽ� C�� �Ű��ش�.
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