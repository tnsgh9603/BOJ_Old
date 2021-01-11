#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

ll arr[101010];
ll tree[404040];
ll lazy[404040][2];
const ll mod = 1e9 + 7;

ll init(int node, int start, int end) { //init(1, 1, n)

	// start와 end가 같으면 맨 아래 노드(리프 노드)까지 내려갔다는 뜻
	if (start == end) {
		return tree[node] = arr[start];
	}

	/* << 현재 노드의 번호가 node 일 때 >>
	노드의 왼쪽 자식 배열 번호 :: node * 2
	노드의 오른쪽 자식 배열 번호 :: node * 2  + 1 */

	int mid = (start + end) >> 1; // 나누기 2한것과 같은 효과
	return tree[node] = (init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end)) % mod;
}

void update_lazy(int node, int start, int end) {

	ll& a1 = lazy[node][0]; // 곱셈 lazy저장
	ll& b1 = lazy[node][1]; // 덧셈 lazy저장

	// 곱해야할게 1이고, 더해야할게 0이면, lazy가 0이므로 return
	if (a1 == 1 && b1 == 0) {
		return;
	}

	// 자식 노드가 있는 수 만큼 덧셈 lazy값에 곱하여 더한다.
    // 자식에게 lazy를 분배하니 자식이 return으로 더해주지 못한 값을 직접 계산한다.
	tree[node] = (a1 * tree[node] + (end - start + 1) * b1) % mod;

	// 리프 노드가 아니라면
	if (start != end) {
		// 자식노드들에 대해서
		for (int i = node * 2; i <= node * 2 + 1; i++) {
			
			// a1은 부모노드의 곱셈 lazy값, a2는 자식노드의 곱셈 lazy값
			// b1은 부모노드의 덧셈 lazy값, b2는 자식노드의 덧셈 lazy값
			ll a2 = lazy[i][0], b2 = lazy[i][1];

			// 이 부분이 제일 중요하다.
			// 자식노드의 곱셈 lazy값은 서로 곱한 후, mod값으로 나누고
			lazy[i][0] = (a1 * a2) % mod;
			// 자식노드의 덧셈 lazy값은 (부모노드의 곱셈 lazy값 * 자식노드의 덧셈 lazy값 + 부모노드의 덧셈 lazy값)을 mod값으로 나눠야한다!!
			lazy[i][1] = (a1 * b2 + b1) % mod;
		}
	}

	// 자식 노드에게 lazy를 짬때린 후, 초기화
	a1 = 1, b1 = 0;
}

/* 1번 쿼리와 2번 쿼리, 3번 쿼리를 합친 함수
if (op == 1) {
	update(1, 1, n, x, y, 1, v);
}
else if (op == 2) {
	update(1, 1, n, x, y, v, 0);
}
else if (op == 3) {
	// 해당 노드의 값을 v로 바꾸는 것은 0을 곱하고 v를 더하는 것으로 계산
	update(1, 1, n, x, y, 0, v);
*/
void update(int node, int start, int end, int left, int right, ll mul, ll sum) {
	
	// 현재 노드에 lazy가 있는지 확인 후, lazy가 있다면 node를 업데이트 해준다.
	update_lazy(node, start, end);

	// 구간이 하나도 속하지 않는다면 return;
	if (right < start || end < left) {
		return;
	}

	// 원하는 구간 내에 있는 노드에 왔을 경우
	if (left <= start && end <= right) {
		lazy[node][0] *= mul;
		lazy[node][0] %= mod;
		lazy[node][1] *= mul;
		lazy[node][1] %= mod;
		lazy[node][1] += sum;
		lazy[node][1] %= mod;
		update_lazy(node, start, end);
		return;
	}

	// 구간에 걸치는 경우
	int mid = start + end >> 1;
	update(node * 2, start, mid, left, right, mul, sum);
	update(node * 2 + 1, mid + 1, end, left, right, mul, sum);

	// 구간이 걸쳐서 속해 있다면 자식 노드를 이용하여 부모 노드를 업데이트 한다.
	tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % mod;
}

ll sum(int node, int start, int end, int left, int right) {

	// 현재 노드에 lazy가 있는지 확인 후, lazy가 있다면 node를 업데이트 해준다.
	update_lazy(node, start, end);
	
	// 구간이 하나도 속하지 않는다면 return;
	if (right < start || end < left) {
		return 0;
	}

	// 원하는 구간 내에 있는 노드에 왔을 경우
	if (left <= start && end <= right) {
		return tree[node] % mod;
	}

	// 구간에 걸치는 경우
	int m = start + end >> 1;
	return (sum(node * 2, start, m, left, right) + sum(node * 2 + 1, m + 1, end, left, right)) % mod;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n);
	
	// 각 트리의 lazy값 초기화
	for (int i = 0; i < 404040; i++) {
		lazy[i][0] = 1, lazy[i][1] = 0;
	}

	int m;
	cin >> m;
	while (m--) {
		int op; 
		cin >> op;
		ll x, y, v; 
		cin >> x >> y;
		if (op != 4) {
			cin >> v;
		}
		if (op == 1) {
			update(1, 1, n, x, y, 1, v);
		}
		else if (op == 2) {
			update(1, 1, n, x, y, v, 0);
		}
		else if (op == 3) {
			// 해당 노드의 값을 v로 바꾸는 것은 0을 곱하고 v를 더하는 것으로 계산
			update(1, 1, n, x, y, 0, v);
		}
		else {
			cout << sum(1, 1, n, x, y) << "\n";
		}
	}
}