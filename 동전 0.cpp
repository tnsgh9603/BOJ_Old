#include <iostream>
#include <vector>
using namespace std;
vector <int> coin;
int main() {
	int N, K, input, cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> input;
		coin.emplace_back(input);
	}
	for (int i = coin.size() - 1; i >= 0; i--) {
		if (K == 0) {
			break;
		}
		if (K < coin[i]) {
			continue;
		}
		else {
			K -= coin[i++];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}