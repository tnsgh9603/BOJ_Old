#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void convert(long long M, int B) {
	vector<int> v;
	while (M) {
		v.push_back(M % B);
		M /= B;
	}
	vector<int> r(v.rbegin(), v.rend());
	cout << (v == r ? 1 : 0) << '\n';
	return;
}
int main() {
	fastio;
	int N, B;
	long long M;
	cin >> N;
	while (N--) {
		cin >> M >> B;
		convert(M, B);
	}
	return 0;
}