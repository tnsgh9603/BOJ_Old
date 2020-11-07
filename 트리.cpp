#include <iostream>
using namespace std;
int pre_order[1001];
int in_order[1001];
int position[1001];
void solve(int ps, int pe, int is, int ie) {
	if (ps > pe || is > ie) {
		return;
	}
	int root = pre_order[ps];
	int ir = position[root];
	int left = ir - is;
	solve(ps + 1, ps + left, is, ir - 1); // 왼쪽 서브트리 탐색
	solve(ps + left + 1, pe, ir + 1, ie); // 오른쪽 서브트리 탐색
	cout << root << " "; // 루트 노드 출력
}
int main() {
	int T, n;
	cin >> T; // 테스트 케이스 수
	for (int i = 1; i <= T; i++) {
		cin >> n; // 노드 수
		for (int j = 0; j < n; j++) {
			cin >> pre_order[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> in_order[j];
		}
		for (int j = 0; j < n; j++) {
			position[in_order[j]] = j; // in_order에서 값 i의 위치를 저장하는 position 배열
		}
		solve(0, n - 1, 0, n - 1);
		cout << "\n";
	}
	return 0;
}
/*
#include <iostream>
using namespace std;
int pre_order[1001];
int in_order[1001];
void solve(int l, int r, int index) {
	if (l > r) {
		return;
	}
	int tmp = in_order[pre_order[index]];
	solve(l, tmp - 1, index + 1); // 왼쪽 서브트리 탐색
	solve(tmp + 1, r, index + tmp - l + 1); // 오른쪽 서브트리 탐색
	cout << pre_order[index] << " "; // 루트 노드 출력
}
int main() {
	int T, n;
	cin >> T; // 테스트 케이스 수
	for (int i = 1; i <= T; i++) {
		cin >> n; // 노드 수
		for (int j = 0; j < n; j++) {
			cin >> pre_order[j];
		}
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			in_order[tmp] = j;
		}
		solve(0, n - 1, 0);
		cout << "\n";
	}
	return 0;
}
*/​