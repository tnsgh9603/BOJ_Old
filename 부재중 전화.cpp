#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> music;
int main() {
	int N, L, D;
	int bell = 0;

	cin >> N >> L >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) { //�뷡�� ����Ǵ� ����
			music.push_back(1);
		}
		for (int j = 0; j < 5; j++) { //�뷡�� ������� �ʴ� ����
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