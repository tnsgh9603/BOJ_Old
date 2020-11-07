#include <iostream>
using namespace std;
int in_order[100001], post_order[100001], position[100001];
void solve(int is, int ie, int ps, int pe) {
	// is -> inorder_start,  ie -> inorder_end
	// ps -> position_start, pe -> position_end
	if (is > ie || ps > pe) {
		return;
	}
	int root = post_order[pe];
	cout << root << ' ';  // ��Ʈ ��� ���
	int ir = position[root]; // in_order �迭 �� ir��ġ�� root���� ����ִ�.
	int left = ir - is;
	solve(is, ir - 1, ps, ps + left - 1); //���� ����Ʈ�� Ž��
	solve(ir + 1, ie, ps + left, pe - 1); // ������ ����Ʈ�� Ž��
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in_order[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> post_order[i];
	}
	for (int i = 0; i < n; i++) {
		position[in_order[i]] = i; // in_order���� �� i�� ��ġ�� �����ϴ� position �迭
	}
	solve(0, n - 1, 0, n - 1);
	return 0;
}