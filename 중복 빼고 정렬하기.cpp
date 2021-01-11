#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[2001];
vector <int> vec;
int main() {
	int n, s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (!arr[s + 1000]++) {
			vec.push_back(s);
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	return 0;
}
