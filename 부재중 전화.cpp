#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> music;
int main() {
	int N, L, D;
	int bell = 0;

	cin >> N >> L >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) { //노래가 재생되는 동안
			music.push_back(1);
		}
		for (int j = 0; j < 5; j++) { //노래가 재생되지 않는 동안
			music.push_back(0);
		}
	}

	while (1) {
		if (bell > music.size()) {
			break;
		}
		if (music[bell] == 0) {
			break;
		}
		else {
			bell = bell + D;
		}
	}
	cout << bell;
}