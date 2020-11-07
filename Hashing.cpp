#include <iostream>
#include <cmath>
using namespace std;
long long mod = 1234567891;
long long q = 1;
int main() {
	int L;
	char sentence[51];
	cin >> L >> sentence;
	long long sum = 0;
	for (int i = 0; i < L; i++) {
		sum += (sentence[i] - 'a' + 1) * q;
		q *= 31;
		q %= mod;
	}
	cout << sum % mod;
	return 0;
}