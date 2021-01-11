#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[100001];
ll tree[400001];

void init(int start, int end, int node) {

	// start와 end가 같으면 맨 아래 노드(리프 노드)까지 내려갔다는 뜻
	if (start == end) {
		tree[node] = a[start];
		return;
	}

	// 세그먼트 트리 생성 리프 노드를 제외한 나머지 노드는 0으로 초기화
	tree[node] = 0;

	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int left, int right, ll k) {	

	// 각 노드에 더해질 k값들을 모두 누적하여 쿼리 수행 시 거쳐가는 모든 노드의 값을 더할 수 있도록 구성.

	// 범위를 벗어난 경우 리턴
	if (start > right || end < left) {
		return;
	}

	// 완전히 범위 내에 들어온 경우 현재 노드에 k를 누적
	if (left <= start && end <= right) {
		tree[node] += k;
		return;
	}

	// 범위가 애매하게 걸치는 경우
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, k);
	update(mid + 1, end, node * 2 + 1, left, right, k);
}

ll getX(int start, int end, int node, int index, ll ans) {

	// index에 맞는 리프 노드까지 이동하며 거치는 노드의 값을 모두 누적한다.
	if (index < start || index > end) {
		return 0;
	}

	ans += tree[node];

	// start == end == index
	if (start == end) {
		return ans; // 리프 노드에 도달하면 누적된 값 리턴
	}

	// 범위가 애매하게 걸치는 경우
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