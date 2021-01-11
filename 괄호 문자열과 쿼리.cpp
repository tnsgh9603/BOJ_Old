#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[100001], tree[400001], lazy[400001];
int init(int node, int left, int right) {

	// �������
	if (left == right) {
		return tree[node] = arr[left];
	}

	//min���� �ʱ�ȭ
	return tree[node] = min(init(node * 2, left, (left + right) / 2), init(node * 2 + 1, (left + right) / 2 + 1, right));
}
void update_lazy(int node, int left, int right) {

	// lazy ���� 0�� �ƴϸ�
	if (lazy[node] != 0) {
		tree[node] += lazy[node];
		// ���� ��尡 �ƴϸ� �ڽĿ��� lazy���� ������
		if (left != right) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		//«������ 0���� �ʱ�ȭ
		lazy[node] = 0;
	}
}
int update_range(int node, int start, int end, int left, int right, int value) {

	// ���� ��忡 lazy�� �ִ��� Ȯ�� ��, lazy�� �ִٸ� node�� ������Ʈ ���ش�.
	update_lazy(node, start, end);

	// ������ �ϳ��� ������ �ʴ´ٸ� return;
	if (start > right || end < left) {
		return tree[node];
	}

	// ���ϴ� ���� ���� �ִ� ��忡 ���� ���
	if (left <= start && end <= right) {
		lazy[node] += value;
		update_lazy(node, start, end);
	}
	else {
		// ������ ���ļ� ���� �ִٸ� �ڽ� ��带 �̿��Ͽ� �θ� ��带 ������Ʈ �Ѵ�.
		// �ϳ��� ������ ������ ��Ʈ������ ������ �ö󰡰� �ȴ�.
		tree[node] = min(update_range(node * 2, start, (start + end) / 2, left, right, value), update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, value));
	}
	return tree[node];
}
int main() {
	int sum = 0, ans = 0, k = 0, n, m;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string sentence;
	cin >> sentence;

	// ǥ���� ���� �ӽ÷� �տ� ' ������
	sentence = "'" + sentence;

	// �Ʒ� �ݺ����� ���ؼ� '('�̸� arr�迭�� 1��, ')'�̸� arr�迭�� 0�� ����.
	// �� ���̶� �ùٸ� ���ڹ迭�� ���� �ʴ´ٸ� ��Ʈ ��忡 -1�� ����ǰ� �ȴ�.
	// �ùٸ� ��ȣ ���ڿ��̸� w���� 0�� ���� �ƴϸ� �ٸ� ���� ����.
	int length = sentence.length();
	for (int i = 1; i < length; i++) {
		// '('�̸� k���� 1 , ')'�̸� k���� -1�� ��
		k = sentence[i] == '(' ? 1 : -1;
		// arr���� 0�� ���� ó������ �� �������� �ùٸ� ��ȣ ���ڿ��̶�� ��
		arr[i] = arr[i - 1] + k;
		sum += k;
	}

	length--;
	init(1, 1, length);
	cin >> n;
	while (n--) {
		cin >> m;
		// -2�� 2�� �������! �߿�! -> '(' �� +1�̰� ')'�� -1�̾��� �ᱹ �ٲ��ָ� +2�� -2�� ����� ��
		k = sentence[m] == '(' ? -2 : 2;
		// m��°�� �ٲ�� �ڿ� �ִ� ��� ������ ���� ������ �����
		update_range(1, 1, length, m, length, k);
		sum += k;
		// '('�̸� ')'��, ')'�̸� '('�� �ٲ���
		sentence[m] = sentence[m] == '(' ? ')' : '(';
		// ��Ʈ ����� ���� (��, ������)�� ������ �ƴϰ� w�� 0�̶�� ���� ���ڿ��̴�.
		ans += (tree[1] > -1 && !sum);
	}
	cout << ans;
}