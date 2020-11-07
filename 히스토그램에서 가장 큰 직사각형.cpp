// ���׸�Ʈ Ʈ��
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
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
		return -1; // ���� ����
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

int main() {
	while (1) {
		cin >> N;
		if (!N) {
			return 0;
		}
		range.resize(N * 4);
		for (int i = 0; i < N; i++) {
			cin >> p[i];
		}
		init(0, N - 1, 1); // ���׸�Ʈ Ʈ�� �ʱ�ȭ
		cout << solve(0, N - 1) << "\n"; // ���� ���
		memset(p, 0, sizeof(p));
	}
	return 0;
}
/*
// �� �������� long long�� �ٿ��ְ� 0�� �Է����� ���������� ���� �ݺ�, ���������� ���ð� �迭 �ʱ�ȭ�� ���ָ� �ȴ�.
#include <iostream>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[1000001] = { 0, };
stack<int> q;
int main() {
    while (1) {
        int N;
        long long ans = 0;
        cin >> N;
        if (N == 0) {
            return 0;
        }

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        q.push(0);
        for (int i = 1; i <= N + 1; i++) {
            while (!q.empty() && arr[q.top()] > arr[i]) {
                int a = q.top();
                long long height = arr[q.top()];
                q.pop();
                long long  width = i - q.top() - 1;
                ans = max(ans, height * width);
            }
            q.push(i);
        }
        cout << ans << "\n";
        while (!q.empty()) {
            q.pop();
        }
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}
*/