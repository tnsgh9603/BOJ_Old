#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[100001], tree[400001], lazy[400001];
int init(int node, int left, int right) {

	// 리프노드
	if (left == right) {
		return tree[node] = arr[left];
	}

	//min으로 초기화
	return tree[node] = min(init(node * 2, left, (left + right) / 2), init(node * 2 + 1, (left + right) / 2 + 1, right));
}
void update_lazy(int node, int left, int right) {

	// lazy 값이 0이 아니면
	if (lazy[node] != 0) {
		tree[node] += lazy[node];
		// 리프 노드가 아니면 자식에게 lazy값을 물려줌
		if (left != right) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		//짬때리고 0으로 초기화
		lazy[node] = 0;
	}
}
int update_range(int node, int start, int end, int left, int right, int value) {

	// 현재 노드에 lazy가 있는지 확인 후, lazy가 있다면 node를 업데이트 해준다.
	update_lazy(node, start, end);

	// 구간이 하나도 속하지 않는다면 return;
	if (start > right || end < left) {
		return tree[node];
	}

	// 원하는 구간 내에 있는 노드에 왔을 경우
	if (left <= start && end <= right) {
		lazy[node] += value;
		update_lazy(node, start, end);
	}
	else {
		// 구간이 걸쳐서 속해 있다면 자식 노드를 이용하여 부모 노드를 업데이트 한다.
		// 하나라도 음수가 나오면 루트노드까지 음수가 올라가게 된다.
		tree[node] = min(update_range(node * 2, start, (start + end) / 2, left, right, value), update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, value));
	}
	return tree[node];
}
int main() {
	int sum = 0, ans = 0, k = 0, n, m;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string sentence;
	cin >> sentence;

	// 표현을 위해 임시로 앞에 ' 더해줌
	sentence = "'" + sentence;

	// 아래 반복문을 통해서 '('이면 arr배열에 1이, ')'이면 arr배열에 0이 들어간다.
	// 한 번이라도 올바른 문자배열이 들어가지 않는다면 루트 노드에 -1이 저장되게 된다.
	// 올바른 괄호 문자열이면 w값에 0이 들어가고 아니면 다른 값이 들어간다.
	int length = sentence.length();
	for (int i = 1; i < length; i++) {
		// '('이면 k값에 1 , ')'이면 k값에 -1이 들어감
		k = sentence[i] == '(' ? 1 : -1;
		// arr값이 0이 들어가면 처음부터 그 범위까지 올바른 괄호 문자열이라는 뜻
		arr[i] = arr[i - 1] + k;
		sum += k;
	}

	length--;
	init(1, 1, length);
	cin >> n;
	while (n--) {
		cin >> m;
		// -2와 2로 해줘야함! 중요! -> '(' 가 +1이고 ')'는 -1이었다 결국 바꿔주면 +2나 -2를 해줘야 함
		k = sentence[m] == '(' ? -2 : 2;
		// m번째가 바뀌면 뒤에 있는 모든 구간에 대해 갱신해 줘야함
		update_range(1, 1, length, m, length, k);
		sum += k;
		// '('이면 ')'로, ')'이면 '('로 바꿔줌
		sentence[m] = sentence[m] == '(' ? ')' : '(';
		// 루트 노드의 값이 (즉, 누적합)이 음수가 아니고 w가 0이라면 옳은 문자열이다.
		ans += (tree[1] > -1 && !sum);
	}
	cout << ans;
}