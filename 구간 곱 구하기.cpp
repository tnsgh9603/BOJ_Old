#include <iostream>
using namespace std;

long long tree[3000000];
long long num[1000001];
long long mod = 1000000007;

long long update(int node, int start, int end, int b, int c) {
    // start�� end ���� ���̿� index�� �ƴϸ� ���ž��� ���� ��带 ��ȯ���ش�. 
    if (!(start <= b && b <= end)) {
        return tree[node];
    }
    // ���� ��� ������Ʈ
    if (start == end) {
        return tree[node] = c;
    }

    int mid = (start + end) / 2;

    /* << ���� ����� ��ȣ�� node �� �� >>
    ����� ���� �ڽ� �迭 ��ȣ :: node * 2
    ����� ������ �ڽ� �迭 ��ȣ :: node * 2  + 1 */

    return tree[node] = ((update(node * 2, start, mid, b, c) % mod) * (update(node * 2 + 1, mid + 1, end, b, c) % mod)) % mod;
}
long long mul(int left, int right, int node, int start, int end) {
    
    if (right < start || end < left) { // �ƿ� ��������� ���x (���̹Ƿ� 0��� 1 return)
        return 1;
    }
    if (left <= start && end <= right) { // ���ϴ� ������ ����� ������ ������ ��
        return tree[node];
    }
    //���߰��ϰ� ��ĥ��
    int mid = (start + end) / 2;
    return ((mul(left, right, node * 2, start, mid) % mod) * (mul(left, right, node * 2 + 1, mid + 1, end) % mod)) % mod;
}
long long init(int node, int start, int end) { // n�� ���� start ~ end�� �ô´�

    if (start == end) { // �� ������ ���(���� ���)���� ���� ��
        return tree[node] = num[start]; // ���� �־���
    }
    int mid = (start + end) / 2;

    /* << ���� ����� ��ȣ�� node �� �� >>
    ����� ���� �ڽ� �迭 ��ȣ :: node * 2
    ����� ������ �ڽ� �迭 ��ȣ :: node * 2  + 1 */

    // �� ����� �ڽ� ��忡�� Ÿ�� �ö�� return ���� �����־� �ڽ��� ��忡 ���� �ִ´�.
    tree[node] = ((init(node * 2, start, mid) % mod) * (init(node * 2 + 1, mid + 1, end) % mod)) % mod;
    return tree[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, 1, N); // �ʱ�ȭ

    for (int i = 1; i <= M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) { // b��° ���� c�� �ٲ۴�.
            update(1, 1, N, b, c); // void update(int node, int start, int end, int t, int diff){}
        }
        else {
            cout << mul(b, c, 1, 1, N) % mod << "\n";
        }
    }
    return 0;
}