#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int main() {
	int N, input, sum = 0, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.emplace_back(input);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
		ans += sum;
	}
	cout << ans;
	return 0;
}