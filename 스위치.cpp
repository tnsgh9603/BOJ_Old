#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
ll init(vll& arr, vll& tree, int node, int start, int end) {

	// 리프 노드까지 도달하면
	if (start == end) {
		return tree[node] = arr[start];
	}

	return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update_lazy(vll& tree, vll& lazy, int node, int start, int end) {

	// lazy값이 1이면 
	// lazy값이 0이 아닐때만 수행, lazy값이 0이면 아무것도 안함
	if (lazy[node] != 0) { //업데이트를 해야 할 경우
		tree[node] = (end - start + 1) - tree[node]; //관할 구역의 개수만큼 더함
		if (start != end) { //리프 노드가 아니면
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		lazy[node] = 0; //업데이트 완료
	}
}

int update_range(vll& tree, vll& lazy, int node, int start, int end, int left, int right) {

	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) { //범위 초과
		return tree[node];
	}
	if (left <= start && end <= right) { //범위 포함
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

	// 범위 밖이면 return 
	if (left > end || right < start) {
		return 0;
	}

	// 범위 안이면
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