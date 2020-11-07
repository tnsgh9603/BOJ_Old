#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int main() {
	int N, M, input, min_answer = 2000000000;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);
	}
	// 없어도 정답처리 되긴되더라
	if (N == 1) {
		cout << vec[0];
		return 0;
	}
	sort(vec.begin(), vec.end());
	int start = 0, end = 1, difference;
	while (start < vec.size() && end < vec.size()) {
		difference = vec[end] - vec[start];
		if (difference == M) {
			min_answer = M;
			break;
		}
		else if (difference > M) {
			min_answer = min(min_answer, difference);
			start++;
		}
		else {
			end++;
		}
	}
	cout << min_answer;
	return 0;
}