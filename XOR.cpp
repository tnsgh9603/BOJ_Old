#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
ll init(vll& arr, vll& tree, int node, int start, int end) {

	// start�� end�� ������ �� �Ʒ� ���(���� ���)���� �������ٴ� ��
	if (start == end) { 
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	/* << ���� ����� ��ȣ�� node �� �� >>
	����� ���� �ڽ� �迭 ��ȣ :: node * 2
	����� ������ �ڽ� �迭 ��ȣ :: node * 2  + 1 */
	return tree[node] = init(arr, tree, node * 2, start, mid) ^ init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update_lazy(vll& tree, vll& lazy, int node, int start, int end) {

	// lazy�� 0�̸� return;
	if (lazy[node] == 0) {
		return;
	}
	
	tree[node] ^= lazy[node] * ((end - start + 1) % 2); 

	// leaf�� �ƴϸ� �ڽĿ��� lazy�� �����ش�.
	if (start != end) { 
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}

	// ������ �� lazy�� �ʱ�ȭ
	lazy[node] = 0; 
}

int update_range(vll& tree, vll& lazy, int node, int start, int end, int left, int right, ll diff) {

	// ���� ��忡 lazy�� �ִ��� Ȯ�� ��, lazy�� �ִٸ� node�� ������Ʈ ���ش�.
	update_lazy(tree, lazy, node, start, end);

	// ������ �ϳ��� ������ �ʴ´ٸ� return
	if (left > end || right < start) { 
		return tree[node];
	}

	// ���ϴ� ���� ���� �ִ� ��忡 ���� ���
	if (left <= start && end <= right) { 
		/* a xor b xor b�� ����� a�� ���� ����, a xor 0�� ����� a�� ���� ����
		� �� b�� ¦�� �� xor�ϸ� 0�� xor�� ���� ����, Ȧ�� �� xor�ϸ� b�� �� �� xor�� ���� ����.
		�׷��Ƿ� update�� ���� ��, tree[node] ^= diff * ((end - start + 1) % 2); �� ���� ������ �� �� �ִ�. */
		tree[node] ^= diff * ((end - start + 1) % 2);
		if (start != end) {
			lazy[node * 2] ^= diff;
			lazy[node * 2 + 1] ^= diff;
		}
		return tree[node];
	}
	return tree[node] = update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff) ^
		update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
}

ll sum(vll& tree, vll& lazy, int node, int start, int end, int left, int right) {

	// update���� ���� lazy�� �ش��ϴ� ������ sum �� �� ������Ʈ ���ش�.
	update_lazy(tree, lazy, node, start, end);

	// �ƿ� ��������� ���x
	if (left > end || right < start) {
		return 0;
	}

	// ���ϴ� ������ ����� ������ ������ ��
	if (left <= start && end <= right) {
		return tree[node];
	}

	//���߰��ϰ� ��ĥ��
	int mid = (start + end) / 2;
	return sum(tree, lazy, node * 2, start, mid, left, right) ^ sum(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n;
	vll arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int h = (int)ceil(log2(n)) + 1;
	int size = (1 << h);
	vll tree(size);
	vll lazy(size);
	init(arr, tree, 1, 0, n - 1);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		if (t == 1) {
			int b, c;
			ll d;
			cin >> b >> c >> d;
			update_range(tree, lazy, 1, 0, n - 1, b, c, d);
		}
		if (t == 2) {
			int b, c; cin >> b >> c;
			cout << sum(tree, lazy, 1, 0, n - 1, b, c) << "\n";
		}
	}
}
/*
#include <iostream>
#include <vector>
using namespace std;
vector <int> vec;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, M, input, i, j, k;
	cin >> N;
	for (int q = 0; q < N; q++) {
		cin >> input;
		vec.push_back(input);
	}
	cin >> M;
	for (int q = 0; q < M; q++) {
		cin >> input;
		if (input == 1) {
			cin >> i >> j >> k;
			for (int e = i; e < j; e++) {
				vec[e] ^= k;
			}
		}
		else if (input == 2) {
			cin >> i >> j;
			int sum = vec[i];
			for (int w = i + 1; w < j; w++) {
				sum ^= vec[w];
			}
			cout << sum << "\n";
		}
	}
	return 0;
}
*/