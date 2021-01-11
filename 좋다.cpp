#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int main() {
	int N;
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int low = 0, high = N - 1, target = vec[i];
		while (low < high) {
			int val = vec[low] + vec[high];
			if (val < target) {
				low++;
			}
			else if (val > target){
				high--;
			}
			else {
				// 두 수가 자기 자신과 같으면 안됨
				if (i != low && i != high) {
					cnt++;
					break;
				}
				if (low == i) {
					low++;
				}
				if (high == i) {
					high--;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}