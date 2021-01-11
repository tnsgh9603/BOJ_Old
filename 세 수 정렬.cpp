#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int main() {
	int n;
	for (int i = 0; i <= 2; i++) {
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i <= 2; i++) {
		cout << vec[i] << " ";
	}
	return 0;
}