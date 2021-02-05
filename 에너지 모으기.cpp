#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> vec;
int max_energy, energy;
void recursion() {
	// 더 이상 없앨 구슬이 없으면 종료
	if (vec.size() == 2) {
		if (max_energy < energy) {
			max_energy = energy;
		}
		return;
	}
	for (int i = 1; i <= vec.size() - 2; i++) {
		int select = vec[i];
		energy = energy + vec[i - 1] * vec[i + 1];
		// 삭제
		vec.erase(vec.begin() + i);
		recursion();
		// 복구
		vec.insert(vec.begin() + i, select);
		energy = energy - vec[i - 1] * vec[i + 1];
	}
}
int main() {
	fastio;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	recursion();
	cout << max_energy;
	return 0;
}