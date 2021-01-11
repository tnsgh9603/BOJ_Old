#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, s;
	cin >> n;
	while (n--) {
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\n";
	}
	return 0;
}