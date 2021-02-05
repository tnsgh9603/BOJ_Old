#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int main() {
	fastio;
	string A, B;
	vector<int> vec;
	cin >> A >> B;
	for (int i = 0; i < A.size(); ++i) {
		vec.push_back(arr[A[i] - 'A']);
		vec.push_back(arr[B[i] - 'A']);
	}
	while (vec.size() > 2) {
		for (int i = 0; i < vec.size() - 1; ++i)
			vec[i] = (vec[i] + vec[i + 1]) % 10;
		vec.pop_back();
	}
	cout << vec[0] << vec[1];
	return 0;
}