#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int arr[150001];
int main() {
	int n1, n2, n3, input, max_ = 0, cnt = 0;
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < n1 + n2 + n3; i++) {
		cin >> input;
		max_ = max(max_, input);
		arr[input]++;
	}
	for (int i = 1; i <= max_; i++) {
		if (arr[i] >= 2) {
			vec.push_back(i);
		}
	}
	cout << vec.size() << "\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\n";
	}
	return 0;
}