#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int main() {
	int a, b;
	cin >> a >> b;
	if ((a + b) % 2 != 0 || a < b) {
		cout << "-1";
	}
	else {
		vec.push_back((a + b) / 2);
		vec.push_back(a - ((a + b) / 2));
		sort(vec.begin(), vec.end(), greater<int>());
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
	}
	return 0;
}