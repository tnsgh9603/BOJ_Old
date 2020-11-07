#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool is_prime(int n) {
	// 2 미만이면 소수 아님
	if (n < 2) {
		return false;
	}
	// 2는 유일한 짝수인 소수
	else if (n == 2) {
		return true;
	}
	// 2말고 나머지 짝수는 모두 합성수
	else if (n % 2 == 0) {
		return false;
	}
	else {
		// 루트 n 까지만 비교해주면 됨
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