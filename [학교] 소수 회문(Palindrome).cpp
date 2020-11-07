#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool is_prime(int n) {
	// 2 �̸��̸� �Ҽ� �ƴ�
	if (n < 2) {
		return false;
	}
	// 2�� ������ ¦���� �Ҽ�
	else if (n == 2) {
		return true;
	}
	// 2���� ������ ¦���� ��� �ռ���
	else if (n % 2 == 0) {
		return false;
	}
	else {
		// ��Ʈ n ������ �����ָ� ��
		for (int i = 3; i < pow(n, 0.5) + 1; i += 2) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
}
bool is_palindrome(string N) {
	for (int i = 0; i < (N.size() / 2); i++) {
		if (N[i] != N[N.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	int N;
	cin >> N;
	while (1) {
		string a = to_string(N);
		if (is_palindrome(a) && is_prime(N)) {
			cout << N;
			return 0;
		}
		N++;
	}
	return 0;
}