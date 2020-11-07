#include <iostream>
#include <vector>
using namespace std;
vector <int> vec;
long long result = 0;
void binary_search(int start, int end ,int target) {
	while (start <= end) {
		long long sum = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < vec.size(); i++) {
			if (mid < vec[i]) {
				sum += vec[i] - mid;
			}
		}
		if (sum < target) {
			end = mid - 1;
		}
		else {
			if (result < mid) {
				result = mid;
			}
			start = mid + 1;
		}
	}
}
int main() {
	int N, M, input, max = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);
		if (max < input) {
			max = input;
		}
	}
	binary_search(0, max, M);
	cout << result;
	return 0;
}