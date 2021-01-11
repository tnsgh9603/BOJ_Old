#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> tree;
long long num[4000001];

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

    long long mid = (start + end) / 2;

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

    int height = (int)ceil(log2(N));
    int tree_size = 1 << (height + 1);
    tree.resize(tree_size);

    init(1, 1, N); // �ʱ�ȭ

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) { // b��° ���� c�� �ٲ۴�.
            long long diff = c - num[b];
            update(1, 1, N, b, diff); // void update(int node, int start, int end, int t, int diff){}
        }
        else {
            if (b > c) {
                swap(b, c);
            }
            cout << sum(b, c, 1, 1, N) << "\n";
        }
    }
}