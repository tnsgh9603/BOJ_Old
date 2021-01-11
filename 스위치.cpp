#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
ll init(vll& arr, vll& tree, int node, int start, int end) {

	// ���� ������ �����ϸ�
	if (start == end) {
		return tree[node] = arr[start];
	}

	return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update_lazy(vll& tree, vll& lazy, int node, int start, int end) {

	// lazy���� 1�̸� 
	// lazy���� 0�� �ƴҶ��� ����, lazy���� 0�̸� �ƹ��͵� ����
	if (lazy[node] != 0) { //������Ʈ�� �ؾ� �� ���
		tree[node] = (end - start + 1) - tree[node]; //���� ������ ������ŭ ����
		if (start != end) { //���� ��尡 �ƴϸ�
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		lazy[node] = 0; //������Ʈ �Ϸ�
	}
}

int update_range(vll& tree, vll& lazy, int node, int start, int end, int left, int right) {

	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) { //���� �ʰ�
		return tree[node];
	}
	if (left <= start && end <= right) { //���� ����
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return tree[node];
	}
	int mid = (start + end) / 2;
	return tree[node] = update_range(tree, lazy, node * 2, start, mid, left, right) + update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

ll sum(vll& tree, vll& lazy, int node, int start, int end, int left, int right) {

	update_lazy(tree, lazy, node, start, end);

	// ���� ���̸� return 
	if (left > end || right < start) {
		return 0;
	}

	// ���� ���̸�
	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = start + end >> 1;
	return sum(tree, lazy, node * 2, start, mid, left, right) + sum(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; 
	cin >> n >> m;

	int tree_size = ceil(log2(n)) + 1;
	vll st(1 << tree_size);
	vll lazy(1 << tree_size);

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd) {
			cout << sum(st, lazy, 1, 1, n, a, b) << '\n';
		}
		else {
			update_range(st, lazy, 1, 1, n, a, b);
		}
	}
}