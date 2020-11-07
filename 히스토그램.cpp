// ���׸�Ʈ Ʈ��
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int p[100001];
vector<int> range;
int init(int left, int right, int node) {
	if (left == right) { // ���� �Ʒ�(���� ���)���� �����Դٴ� ��
		return range[node] = left; // �ε����� ����
	}

	/* << ���� ����� ��ȣ�� node �� �� >>
	����� ���� �ڽ� �迭 ��ȣ :: node * 2
	����� ������ �ڽ� �迭 ��ȣ :: node * 2  + 1 */
	int mid = (left + right) / 2;
	int lo = init(left, mid, node * 2);
	int hi = init(mid + 1, right, node * 2 + 1);

	if (p[lo] <= p[hi]) {
		return range[node] = lo; // ���� ���� �ּҰ��� ������ �ε����� ��ġ�� ����
	}	
	else {
		return range[node] = hi;
	}
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (left <= nodeLeft && nodeRight <= right) {
		return range[node]; // ���ϴ� ���� ���� ���� ��� ��ȯ
	}
	if (nodeRight < left || right < nodeLeft) {
		return -1; // ���� ����� -1
	}
	int mid = (nodeLeft + nodeRight) / 2;
	int lo = query(left, right, node * 2, nodeLeft, mid); // (nodeLeft, mid) ������ �ּҰ� �ε���
	int hi = query(left, right, node * 2 + 1, mid + 1, nodeRight); // (mid+1, nodeRight) ������ �ּҰ� �ε���

	if (lo == -1) {
		return hi;
	}
	if (hi == -1) {
		return lo;
	}
	if (p[lo] <= p[hi]) {
		return lo; // �ּҰ��� ���� �ε��� ��ġ ��ȯ.
	}
	else {
		return hi;
	}
}

long long solve(int left, int right) {
	if (left > right) {
		return -1; // ��������
	}
	int loIdx = query(left, right, 1, 0, N - 1); // (left,right) ������ �ּҰ��� ���� �ε��� ���ϱ�
	long long res = (long long)((long long)right - (long long)left + 1) * p[loIdx]; // (left, right) ������ ��� �����ϰ� ���� �� �ִ� ���簢�� ����

	if (loIdx != left) {
		res = max(res, solve(left, loIdx - 1)); // (left, loIdx-1) ���� ������ ���� �� �ִ� ���簢���� �ִ� ���� �ֽ�ȭ
	}
	if (loIdx != right) {
		res = max(res, solve(loIdx + 1, right)); // (loIdx+1, right) ����
	}
	return res; // �ִ� ���� ��ȯ
}

int main(){
	cin >> N;
	range.resize(4 * N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	
	init(0, N - 1, 1); // ���׸�Ʈ Ʈ�� �ʱ�ȭ

	cout << solve(0, N - 1); // ���� ���
	return 0;
}
/* ������ �̿�
#include <iostream>
#include <stack> // ������ ����ϱ� ����
#include <algorithm> // max �Լ� ����� ����
using namespace std;

stack<int> q; 
int arr[100001] = { 0, };
int main() {
	int N, ans = 0; 
	cin >> N; // N�� ������׷��� ���� ĭ�� ��

	for (int i = 1; i <= N; i++) {
		cin >> arr[i]; // N��ŭ �Է¹޾���
	}

	q.push(0); // ���� �κ��� ������ֱ� ���� 0�� �־���
	for (int i = 1; i <= N + 1; i++){ // ���� �κ��� ������ֱ� ���� N+1���� �־���
		while (arr[q.top()] > arr[i]){ // ���̰� �۰ų� ���� ���� ���� ������ ��� push ���ְ�, 
			                           // ���̰� �۰ų� ���� ���� ������ �簢���� ���̸� �������
			int height = arr[q.top()]; // ���� ���� ���
			q.pop();
			int width = i - q.top() - 1; // ���� ���� ���
			ans = max(ans, height * width); // �簢���� ���̸� ����ؼ� ���� �ִ� �ͺ��� �� ũ�� ����
		}
		q.push(i);
	}
	cout << ans;
	return 0;
}*/


/* 
#include <iostream>
using namespace std;
int arr[100001] = { 0, };
int main() {
	int N, max = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		int k = 1, q = -1;
		while (arr[i + k] >= arr[i] && i + k < N) {
			k++;
		}
		while (arr[i + q] >= arr[i] && i + q >= 0) {
			q--;
		}
		int ans = arr[i] * (k + abs(q) - 1);
		if (max < ans) {
			max = ans;
		}
	}
	cout << max;
	return 0;
}*/