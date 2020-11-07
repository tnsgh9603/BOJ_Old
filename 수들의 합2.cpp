#include <iostream>
#include <vector>
using namespace std;
vector <int> vec;
int main() {
	int N, M, input;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		vec.push_back(input);
	}
	int start = 0, end = 0, cnt = 0;
	while (1) {
		if (start > end || start >= vec.size() || end >= vec.size()) {
			break;
		}
		int sum = 0;
		for (int i = start; i <= end; i++) {
			sum += vec[i];
		}
		if (sum == M) {
			cnt++;
			start++;
			end++;
		}
		else if (sum > M) {
			if (start == end) {
				start++;
				end++;
			}
			else {
				start++;
			}
		}
		else {
			end++;
		}
	}
	cout << cnt;
	return 0;
}