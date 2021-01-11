#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

ll arr[101010];
ll tree[404040];
ll lazy[404040][2];
const ll mod = 1e9 + 7;

ll init(int node, int start, int end) { //init(1, 1, n)

	// start�� end�� ������ �� �Ʒ� ���(���� ���)���� �������ٴ� ��
	if (start == end) {
		return tree[node] = arr[start];
	}

	/* << ���� ����� ��ȣ�� node �� �� >>
	����� ���� �ڽ� �迭 ��ȣ :: node * 2
	����� ������ �ڽ� �迭 ��ȣ :: node * 2  + 1 */

	int mid = (start + end) >> 1; // ������ 2�ѰͰ� ���� ȿ��
	return tree[node] = (init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end)) % mod;
}

void update_lazy(int node, int start, int end) {

	ll& a1 = lazy[node][0]; // ���� lazy����
	ll& b1 = lazy[node][1]; // ���� lazy����

	// ���ؾ��Ұ� 1�̰�, ���ؾ��Ұ� 0�̸�, lazy�� 0�̹Ƿ� return
	if (a1 == 1 && b1 == 0) {
		return;
	}

	// �ڽ� ��尡 �ִ� �� ��ŭ ���� lazy���� ���Ͽ� ���Ѵ�.
    // �ڽĿ��� lazy�� �й��ϴ� �ڽ��� return���� �������� ���� ���� ���� ����Ѵ�.
	tree[node] = (a1 * tree[node] + (end - start + 1) * b1) % mod;

	// ���� ��尡 �ƴ϶��
	if (start != end) {
		// �ڽĳ��鿡 ���ؼ�
		for (int i = node * 2; i <= node * 2 + 1; i++) {
			
			// a1�� �θ����� ���� lazy��, a2�� �ڽĳ���� ���� lazy��
			// b1�� �θ����� ���� lazy��, b2�� �ڽĳ���� ���� lazy��
			ll a2 = lazy[i][0], b2 = lazy[i][1];

			// �� �κ��� ���� �߿��ϴ�.
			// �ڽĳ���� ���� lazy���� ���� ���� ��, mod������ ������
			lazy[i][0] = (a1 * a2) % mod;
			// �ڽĳ���� ���� lazy���� (�θ����� ���� lazy�� * �ڽĳ���� ���� lazy�� + �θ����� ���� lazy��)�� mod������ �������Ѵ�!!
			lazy[i][1] = (a1 * b2 + b1) % mod;
		}
	}

	// �ڽ� ��忡�� lazy�� «���� ��, �ʱ�ȭ
	a1 = 1, b1 = 0;
}

/* 1�� ������ 2�� ����, 3�� ������ ��ģ �Լ�
if (op == 1) {
	update(1, 1, n, x, y, 1, v);
}
else if (op == 2) {
	update(1, 1, n, x, y, v, 0);
}
else if (op == 3) {
	// �ش� ����� ���� v�� �ٲٴ� ���� 0�� ���ϰ� v�� ���ϴ� ������ ���
	update(1, 1, n, x, y, 0, v);
*/
void update(int node, int start, int end, int left, int right, ll mul, ll sum) {
	
	// ���� ��忡 lazy�� �ִ��� Ȯ�� ��, lazy�� �ִٸ� node�� ������Ʈ ���ش�.
	update_lazy(node, start, end);

	// ������ �ϳ��� ������ �ʴ´ٸ� return;
	if (right < start || end < left) {
		return;
	}

	// ���ϴ� ���� ���� �ִ� ��忡 ���� ���
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

	// ������ ��ġ�� ���
	int mid = start + end >> 1;
	update(node * 2, start, mid, left, right, mul, sum);
	update(node * 2 + 1, mid + 1, end, left, right, mul, sum);

	// ������ ���ļ� ���� �ִٸ� �ڽ� ��带 �̿��Ͽ� �θ� ��带 ������Ʈ �Ѵ�.
	tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % mod;
}

ll sum(int node, int start, int end, int left, int right) {

	// ���� ��忡 lazy�� �ִ��� Ȯ�� ��, lazy�� �ִٸ� node�� ������Ʈ ���ش�.
	update_lazy(node, start, end);
	
	// ������ �ϳ��� ������ �ʴ´ٸ� return;
	if (right < start || end < left) {
		return 0;
	}

	// ���ϴ� ���� ���� �ִ� ��忡 ���� ���
	if (left <= start && end <= right) {
		return tree[node] % mod;
	}

	// ������ ��ġ�� ���
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
	
	// �� Ʈ���� lazy�� �ʱ�ȭ
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
			// �ش� ����� ���� v�� �ٲٴ� ���� 0�� ���ϰ� v�� ���ϴ� ������ ���
			update(1, 1, n, x, y, 0, v);
		}
		else {
			cout << sum(1, 1, n, x, y) << "\n";
		}
	}
}