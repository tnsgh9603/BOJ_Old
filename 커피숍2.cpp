#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


long long tree[400001];
long long num[400001];

void update(int node, int start, int end, int b, long long diff) {
    if (start <= b && b <= end) {
        tree[node] += diff; // ���� ���� ���� ��� ���̸�ŭ + ����
    }
    else {
        return; // ���� ���� ��� ��� x
    }
    if (start == end) {  // �� ������ ���(���� ���)���� ������ �׸� ��.
        return;
    }

    int mid = (start + end) / 2;

    /* << ���� ����� ��ȣ�� node �� �� >>
    ����� ���� �ڽ� �迭 ��ȣ :: node * 2
    ����� ������ �ڽ� �迭 ��ȣ :: node * 2  + 1 */

    update(node * 2, start, mid, b, diff);
    update(node * 2 + 1, mid + 1, end, b, diff);
}
long long sum(int left, int right, int node, int start, int end) {
    if (left <= start && end <= right) { // ���ϴ� ������ ����� ������ ������ ��
        return tree[node];
    }
    if (right < start || end < left) { // �ƿ� ��������� ���x
        return 0;
    }

    //���߰��ϰ� ��ĥ��
    long long mid = (start + end) / 2;
    return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid + 1, end);
}
long long init(int node, int start, int end) { // n�� ���� start ~ end�� �ô´�

    if (start == end) { // �� ������ ���(���� ���)���� ���� ��
        return tree[node] = num[start]; // ���� �־���
    }
    int mid = (start + end) / 2;

    /* << ���� ����� ��ȣ�� node �� �� >>
    ����� ���� �ڽ� �迭 ��ȣ :: node * 2
    ����� ������ �ڽ� �迭 ��ȣ :: node * 2  + 1 */

    tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    return tree[node];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    init(1, 1, N); // �ʱ�ȭ

    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b) {
            swap(a, b);
        }
        cout << sum(a, b, 1, 1, N) << "\n";
        long long diff = d - num[c];
        // c��° ���� d�� �ٲ۴�.
        num[c] = d;
        update(1, 1, N, c, diff); 
    }
}
