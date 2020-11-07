#include <iostream>
using namespace std;
int main() {
	int N, K, a = 1, b = 1;
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		a *= N;
		N--;
	}
	for (int i = 1; i <= K; i++) {
		b *= i;
	}
	cout << a / b;
	return 0;
}