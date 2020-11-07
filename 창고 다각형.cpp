#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int arr[1001];
int main() {
	int N;
	cin >> N;

	int start = 11111, end = -1, a, b, Max = -1, idx1 = 0;
	for (int n = 0; n < N; n++) {
		cin >> a >> b;
		end = max(end, a);
		start = min(start, a);
		if (Max < b) { // Max���� ��ü���� ���� ū ���� ����, idx1���� �� ������ �ε��� ����
			Max = b;
			idx1 = a;
		} 
		arr[a] = b;
	}

	int res = 0;
	res += Max;

	stack <int> width;
	width.push(0);
	for (int i = start; i < idx1; i++) { // ���� ����� ���� ����
		if (width.top() < arr[i]) {
			width.pop();
			width.push(arr[i]);
		}
		res += width.top();
	}
	
	// ���� ����
	while (!width.empty()) {
		width.pop();
	}

	width.push(0);
	for (int i = end; i > idx1; i--) { //���� ����� ������ ����
		if (width.top() < arr[i]) {
			width.pop();
			width.push(arr[i]);
		}
		res += width.top();
	}

	cout << res;

	return 0;
}