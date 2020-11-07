#include <iostream>
using namespace std;

long long tree[3000000];
long long num[1000001];

void update(int node, int start, int end, int b, int diff) {
    if (start<= b && b <= end) {
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
    int mid = (start + end) / 2;
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
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, 1, N); // �ʱ�ȭ

    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) { // b��° ���� c�� �ٲ۴�.
            int diff = c - num[b]; 
            num[b] = c;
            update(1, 1, N, b, diff); // void update(int node, int start, int end, int t, int diff){}
        }
        else {
            cout << sum(b, c, 1, 1, N) << "\n";
        }
    }
}