#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[100001];
ll tree[400001];

void init(int start, int end, int node) {

	// start�� end�� ������ �� �Ʒ� ���(���� ���)���� �������ٴ� ��
	if (start == end) {
		tree[node] = a[start];
		return;
	}

	// ���׸�Ʈ Ʈ�� ���� ���� ��带 ������ ������ ���� 0���� �ʱ�ȭ
	tree[node] = 0;

	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int left, int right, ll k) {	

	// �� ��忡 ������ k������ ��� �����Ͽ� ���� ���� �� ���İ��� ��� ����� ���� ���� �� �ֵ��� ����.

	// ������ ��� ��� ����
	if (start > right || end < left) {
		return;
	}

	// ������ ���� ���� ���� ��� ���� ��忡 k�� ����
	if (left <= start && end <= right) {
		tree[node] += k;
		return;
	}

	// ������ �ָ��ϰ� ��ġ�� ���
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, k);
	update(mid + 1, end, node * 2 + 1, left, right, k);
}

ll getX(int start, int end, int node, int index, ll ans) {

	// index�� �´� ���� ������ �̵��ϸ� ��ġ�� ����� ���� ��� �����Ѵ�.
	if (index < start || index > end) {
		return 0;
	}

	ans += tree[node];

	// start == end == index
	if (start == end) {
		return ans; // ���� ��忡 �����ϸ� ������ �� ����
	}

	// ������ �ָ��ϰ� ��ġ�� ���
	int mid = (start + end) / 2;
	return getX(start, mid, node * 2, index, ans) + getX(mid + 1, end, node * 2 + 1, index, ans);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	init(1, n, 1);
	cin >> m;

	while (m--) {
		int q, left, right, index;
		ll k;
		cin >> q;
		if (q == 1) {
			cin >> left >> right >> k;
			update(1, n, 1, left, right, k);
		}
		if (q == 2) {
			cin >> index;
			cout << getX(1, n, 1, index, 0) << '\n';
		}
	}
}