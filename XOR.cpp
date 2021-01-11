#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
ll init(vll& arr, vll& tree, int node, int start, int end) {

	// start와 end가 같으면 맨 아래 노드(리프 노드)까지 내려갔다는 뜻
	if (start == end) { 
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	/* << 현재 노드의 번호가 node 일 때 >>
	노드의 왼쪽 자식 배열 번호 :: node * 2
	노드의 오른쪽 자식 배열 번호 :: node * 2  + 1 */
	return tree[node] = init(arr, tree, node * 2, start, mid) ^ init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update_lazy(vll& tree, vll& lazy, int node, int start, int end) {

	// lazy가 0이면 return;
	if (lazy[node] == 0) {
		return;
	}
	
	tree[node] ^= lazy[node] * ((end - start + 1) % 2); 

	// leaf가 아니면 자식에게 lazy를 물려준다.
	if (start != end) { 
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}

	// 물려준 후 lazy는 초기화
	lazy[node] = 0; 
}

int update_range(vll& tree, vll& lazy, int node, int start, int end, int left, int right, ll diff) {

	// 현재 노드에 lazy가 있는지 확인 후, lazy가 있다면 node를 업데이트 해준다.
	update_lazy(tree, lazy, node, start, end);

	// 구간이 하나도 속하지 않는다면 return
	if (left > end || right < start) { 
		return tree[node];
	}

	// 원하는 구간 내에 있는 노드에 왔을 경우
	if (left <= start && end <= right) { 
		/* a xor b xor b의 결과는 a의 값과 같고, a xor 0의 결과도 a의 값과 같다
		어떤 수 b를 짝수 번 xor하면 0을 xor한 값과 같고, 홀수 번 xor하면 b를 한 번 xor한 값과 같다.
		그러므로 update를 해줄 때, tree[node] ^= diff * ((end - start + 1) % 2); 와 같은 식으로 할 수 있다. */
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

	// update이후 남은 lazy를 해당하는 구간을 sum 할 때 업데이트 해준다.
	update_lazy(tree, lazy, node, start, end);

	// 아예 벗어나있을때 고려x
	if (left > end || right < start) {
		return 0;
	}

	// 구하는 구간이 노드의 구간을 포함할 때
	if (left <= start && end <= right) {
		return tree[node];
	}

	//어중간하게 겹칠때
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