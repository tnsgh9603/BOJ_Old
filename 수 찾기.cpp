#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> arr;
int binary_search(int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		int ans = vec[mid];
		if (target == ans) {
			return 1;
		}
		//ans�� target���� ������ ������ ���� ���� Ž��
		else if (target > ans) {
			start = mid + 1;
		}
		//ans�� target���� ũ�ų� ������ ���� ���� ���� Ž��
		else {
			end = mid - 1;
		}
	}
	return 0;
}
int main() {
	int n, m, input1, input2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input1;
		vec.push_back(input1);
	}
	sort(vec.begin(), vec.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input2;
		arr.push_back(input2);
	}
	for (int i = 0; i < m; i++) {
		int target = arr[i];
		cout << binary_search(0, vec.size() - 1, target) << "\n";
	}
	return 0;
}