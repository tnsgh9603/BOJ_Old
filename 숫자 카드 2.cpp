#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int main() {
	int N, M, input1, input2;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input1;
		vec.push_back(input1);
	}
	sort(vec.begin(), vec.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input2;
		cout << lower_bound(vec.begin(), vec.end(), input2 + 1) - lower_bound(vec.begin(), vec.end(), input2) << " ";
	}
	return 0;
}